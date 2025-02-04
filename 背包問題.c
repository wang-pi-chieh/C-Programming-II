#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int comp(const void* p, const void* q);

struct things {
	int v, w; //v: value  //w: weight
	double vw; // v/w
};

things item[120];

//int item_value[100], item_weight[100];
//double item_vw = 0;  // v/w 

int main() {
	int n; //n:items;
	int k; //k:capacity
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &item[i].w, &item[i].v);
		item[i].vw = item[i].v / item[i].w;
	}
	
	qsort(item, n, sizeof(struct things), comp); //struct的東西要怎麼放在函式括號中的的第一個位置 
	//第一個參數是要放讓程式知道從哪裡開始排序

	//for (int i = 0; i < n; i++) {
	//	printf("%d %d\n", item[i].w, item[i].v);
	//}

	double value = 0;
	for (int j = 0; j < n; j++) {
		if (k >= item[j].w) {
			value += item[j].v;
			k -= item[j].w; //要用減的，因為一個物品只有一個
		}
		else {
			value += (k * item[j].vw);
			break;
		}		
	}
	printf("%lf\n", value);
	return 0;
}

int comp(const void* p, const void* q) {
	int A = *(int*)p;
	int B = *(int*)q;
	if (A == B) {
		return 0;
	}
	return(A < B) ? 1 : -1;
	//return item_value[*(int*)p] - item_value[*(int*)q];
}



//#include <stdio.h>
//#include <stdlib.h>
//#pragma warning(disable:4996)
//
//int comp(const void* p, const void* q);
//
////struct things {
////	int v, w; //v:value  //w:weight
////	double vw; // v/w
////};
////
////things item[100];
//
//int item_value[100], item_weight[100];
//double item_vw = 0;  // v/w 
//
//int main() {
//	int n; //N:items;
//	int w; //W:capacity
//	scanf("%d%d", &n, &w);
//	for (int i = 0; i < n; i++) {
//		scanf("%d%d", &item_value[i], &item_weight[i]);
//	}
//	qsort(item_value, n, sizeof(int), comp); //struct的東西要怎麼放在函式括號中的的第一個位置
//
//	/*for (int i = 0; i < n; i++) {
//		printf("%d %d\n", item_value[i], item_weight[i]);
//	}*/
//
//	int value = 0;
//	for (int j = 0; j < n; j++) {
//		item_vw = w / item_value[j];
//		value = value + (item_vw * item_weight[j]);
//		w = w % item_value[j];
//	}
//	printf("%d\n", value);
//	return 0;
//}
//
//int comp(const void* p, const void* q) {
//	int A = *(int*)p;
//	int B = *(int*)q;
//	if (A == B) {
//		return 0;
//	}
//	return(A < B) ? 1 : -1;
//	//return item_value[*(int*)p] - item_value[*(int*)q];
//}


//
//#include <stdio.h>
//#include <stdlib.h>
//#pragma warning(disable:4996)
//
//int comp(const void* p, const void* q);
//
////struct things {
////	int v, w; //v:value  //w:weight
////	double vw; // v/w
////};
////
////things item[100];
//
//int item[100][2];
////int item_value[100], item_weight[100];
//double item_vw = 0;  // v/w 
//
//int main() {
//	int n; //N:items;
//	int w; //W:capacity
//	scanf("%d%d", &n, &w);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < 2; j++) {
//			scanf("%d", &item[i][j]);
//		}
//	}
//	qsort(item, n, sizeof(int), comp); //struct的東西要怎麼放在函式括號中的的第一個位置
//	qsort(item, n, sizeof(int), comp); //struct的東西要怎麼放在函式括號中的的第一個位置
//
//	/*for (int i = 0; i < n; i++) {
//		printf("%d %d\n", item_value[i], item_weight[i]);
//	}*/
//
//	int value = 0;
//	for (int j = 0; j < n; j++) {
//		item_vw = w / item[j][0];
//		value = value + (item_vw * item[j][1]);
//		w = w % item[j][0];
//	}
//	printf("%d\n", value);
//	return 0;
//}
//
//int comp(const void* p, const void* q) {
//	int A = *(int*)p;
//	int B = *(int*)q;
//	if (A == B) {
//		return 0;
//	}
//	return(A < B) ? 1 : -1;
//	//return item_value[*(int*)p] - item_value[*(int*)q];
//}