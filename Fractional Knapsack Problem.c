#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//注意qsort和comp的寫法!!!!

int comp(const void* p, const void* q); //比較

struct things {
	int v;
	int w; //v:value  //w:weight  
	double b;  //b:break(v/w)
};

struct things item[100000]; //全部都ok之後要來修改陣列大小的問題 //有N個東西=item

int main() {
	int N; //N:items;
	int W; //W:capacity
	scanf("%d%d", &N, &W);

	for (int i = 0; i < N; i++) {
		scanf("%d%d", &item[i].v, &item[i].w);
		item[i].b = (double)item[i].v / item[i].w; //整數除以整數會是整數類型，所以可以直接在前面加(double)轉數值類型
	}

	qsort(item, N, sizeof(struct things), comp);

	double value = 0;
	for (int i = 0; i < N; i++) {
		if (W == 0) { //沒有容量可以放了
			break;
		}
		if (W >= item[i].w) {  //容量大於物品i的容量即放得下
			value += item[i].v;
			W -= item[i].w;
		}
		else { //容量比物品i的容量小，但還有些許容量
			value += (item[i].b * W); //根據剩餘重量按比例增加價值
			W = 0;
			break;
		}
	}
	printf("%.6f\n", value);
}

//int comp(const void* p, const void* q) {
//	int A = *(int*)p;
//	int B = *(int*)q;
//
//	if (A == B) {
//		return 0;
//	}
//	return (A < B) ? -1 : 1;
//}


int comp(const void* p, const void* q) {
	const struct things* A = (const struct things*)p;  //這行可以不用寫，寫了只是整齊
	const struct things* B = (const struct things*)q;  //這行可以不用寫，寫了只是整齊

	if (A->b == B->b) {
		return 0;
	}

	/*if ((const struct things*)p->b == (const struct things*)q->b) {
		return 0;
	}*/  //與60~62行同義
	return (A->b < B->b) ? 1 : -1; //注意排序順序，需要從大到小排列
}

/*在comp函式中寫到A->b，其所指的意思是A這個指標指向的結構變數的內容，又可寫成:(*A).b*/