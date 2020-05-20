#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ex1.h"

blockInfo *findFreeBlock(size_t size){
	blockInfo* pCurr;
	pCurr = head;

	while(pCurr){
		if (pCurr->isFree && pCurr->Size > size)
			return pCurr;
		
		pCurr = pCurr->Next;

	}
	return NULL;

}

void *allocteAlign(size_t size, size_t align){
	void *pCurr, *pBlockInfo, *pAlign;
	
	 /* tạo vùng nhớ để lưu trữ thông tin block, sử dụng khi free*/ 
	if (sbrk(sizeof(blockInfo)) == (void*)-1)
		return NULL;

	pCurr = sbrk(0); // Lấy địa chỉ hiện tại 

	/* di chuyển đến địa chỉ thỏa mãn chia hết cho align*/	
	size_t offset = (size_t)pCurr % align;
	offset = align - offset; // số byte cần thêm chia hết cho align 
	
	/* di chuyen den vi tri thoa man*/
	if (sbrk(offset) == (void*)-1)
		return NULL;
	
	/*lay dia chi da thoa man algin*/
	pAlign = sbrk(0);

	/*Cap phat kich thuoc size theo yeu cau*/
	if (sbrk(size) == (void*)-1)
		return NULL;
	
	/*Tra lai gia tri cua blockInfo*/
	pBlockInfo = pAlign - sizeof(blockInfo);
	
	return pBlockInfo;
}

void *aligned_malloc(unsigned int size, unsigned int align){
	void* returnBlock;
	void* newBlock;
	blockInfo* Info;
	
	Info = findFreeBlock(size);
	if (Info != NULL){
			Info->isFree = 0;
			return (void *)(Info + 1);
	}

	newBlock = allocteAlign(size, align);

	/*luu thong tin lai*/
	Info = newBlock;
	Info->Size = size;
	Info->Next = NULL;

	/*cập nhật lại trạng thái của con trỏ */
	if (!head)
		head = newBlock;
	if (tail)
		tail->Next = Info;
	tail = Info;

	/* Bởi vì blockInfo chúng ta chỉ dùng cho việc free sau này, nên khi return chúng ta + 1 để thoát khỏi vùng này chuyển sang vùng không gian ta muốn sử dụng. */
	return (void*)(Info + 1);
}

void *aligned_free(void* ptr){
	if (ptr == NULL)
		return NULL;
	
	blockInfo *Info;
	blockInfo *temp;

	void* AddrOfBreak;
	AddrOfBreak = sbrk(0);

	/*lay dia chi cua blockInfo*/
	Info = (blockInfo *)ptr - 1;

/*Nếu là block cuối cùng của heap thì ta thu hồi vùng heap này,
nếu không thì chỉ cần đánh dấu rồi dịch địa chỉ lại, sau này dùng hàm findFreeBlock tái sử dụng   */
	if (ptr + Info->Size == AddrOfBreak){
		if (head == tail)
			head = tail = NULL;
		else{
						
			temp = head;
			while(temp){
				if (temp->Next == tail){
					temp->Next = NULL;
					tail = temp;
				}
				temp = temp->Next;
			}
		}
	}

	/*dich chuyen con tro quay ve vi tri truoc do*/
	sbrk(0 - sizeof(blockInfo) - Info->Size);
	
	return sbrk(0);

}

