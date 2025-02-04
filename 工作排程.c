//#include <stdio.h>
//#include <stdlib.h>
//#pragma warning(disable:4996)
//
//struct job
//{
//    int s, e;
//};
//
//int cmp(const void* a, const void* b)
//{
//    struct job* jobA = (struct job*)a;
//    struct job* jobB = (struct job*)b;
//    return (jobA->e - jobB->e);
//}
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    struct job jb[101];
//    for (int i = 0; i < n; i++)
//        scanf("%d %d", &jb[i].s, &jb[i].e);
//    qsort(jb, n, sizeof(struct job), cmp);
//    int ans = 0;
//    for (int i = 0, now = -1; i < n; i++)
//    {
//        if (now <= jb[i].s)
//        {
//            ans++;
//            now = jb[i].e;
//        }
//    }
//    printf("%d\n", ans);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#pragma warning(disable:4996)
//
//int index[150];
//int record[150][150]; //紀錄每個工作的開始與結束時間
//int comp(const void* p, const void* q);
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d%d", record[i][i]);
//	}
//}
//
//
//int comp(const void* p, const void* q) {
//	return record[*(int*)p] - record[*(int*)q];
//}


#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int index[150];
int comp(const void* p, const void* q);

struct job {
	int s, e;
};

job jb[150] = { 0 }; //紀錄每個工作的開始與結束時間

int main() {
	int n;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &jb[i].s, &jb[i].e);
	}
}


int comp(const void* p, const void* q) {
	return jb[*(int*)p] - jb[*(int*)q];
}