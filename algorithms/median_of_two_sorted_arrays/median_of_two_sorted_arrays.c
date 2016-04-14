#include <stdio.h>

double findKth(int * a, int ma, int* b, int mb, int k) {
	if (ma > mb)
		return findKth(b, mb, a, ma, k);
	if (ma == 0)
		return b[k-1];
	if (k == 1)
		return (a[0] < b[0]) ? a[0] : b[0];

	int pa = (ma < k/2) ? ma : k/2;
	int pb = k - pa;

	if (a[pa-1] < b[pb-1])
		return findKth(a+pa, ma - pa, b, mb, k-pa);
	else if (a[pa-1] > b[pb-1])
		return findKth(a, ma, b+pb, mb-pb, k-pb);
	else
		return a[pa-1];
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

	int total = nums1Size + nums2Size;
	if (total & 0x1) {
		return findKth(nums1, nums1Size, nums2, nums2Size, total/2+1);
		
	} else {
		return (findKth(nums1, nums1Size, nums2, nums2Size, total/2) + findKth(nums1, nums1Size, nums2, nums2Size, total/2+1))/2.0;
	}
}


int main(int argc, char* argv[]) {
	int a[] = {1, 2, 3};
	int b[] = {2, 3, 4};
	double xxx = findMedianSortedArrays(a, 3, b, 3);
	printf("%f\n", xxx);

}
