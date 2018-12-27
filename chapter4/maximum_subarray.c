#include <stdio.h>
#include "limits.h"

typedef struct array_param
{
	int left_idx;
	int right_idx;
	int sum;
} ap;

ap max_sub_cross_array(int* arr, int low, int mid, int high) {
	int sum = 0;
	int left_sum, right_sum, left_idx, right_idx; 
	left_sum = right_sum = INT_MIN;

	for (int i = mid; i >= low; i--) {
		sum += arr[i];
		if (left_sum < sum) {
			left_sum = sum;
			left_idx = i;
		}
	}
	sum = 0;
	for (int i = mid + 1; i <= high; i++) {
		sum += arr[i];
		if (right_sum < sum) {
			right_sum = sum;
			right_idx = i;
		}
	}

	ap a;
	a.left_idx = left_idx;
	a.right_idx = right_idx;
	a.sum = left_sum + right_sum;

	return a;
}

ap max_sub_array(int* arr, int low, int high) {
	ap ret, ap_low, ap_high, ap_cross;



	if (high == low) {
		ret.left_idx = low;
		ret.right_idx = high;
		ret.sum = arr[low];

		return ret;
	} else {
		int mid = (low + high) / 2;
		ap_low = max_sub_array(arr, low, mid);
		ap_high = max_sub_array(arr, mid + 1, high);
		ap_cross = max_sub_cross_array(arr, low, mid, high);

		if ((ap_low.sum > ap_high.sum) && (ap_low.sum > ap_cross.sum)) 
			return ap_low;
		else if ((ap_high.sum > ap_low.sum) && (ap_high.sum > ap_cross.sum)) 
			return ap_high;
		else
			return ap_cross;
	}


}

int main(int argc, char const *argv[])
{
	int a[10] = {-1, 2, 3, -4, 5, 6, -7, 8, -9, -10};
	// int a[2] = {1, 1};
	ap a1 = max_sub_array(a, 0, 9);
	printf("%d\t%d\t%d\t", a1.sum, a1.left_idx, a1.right_idx);
	return 0;
}