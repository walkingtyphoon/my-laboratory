//
// Created by walking typhoon on 2025/11/5.
//

void QuickSort(int *arr, int begin, int end) {
    //递归出口
    if (begin >= end)
        return;

    int left = begin, right = end;
    int pivot = arr[left]; //选择第一个数据为基准值，0下标的位置即为坑
    while (left < right) {
        //内部循环可能会出现left==right的情况，所以内部也需要判断
        while (left < right && arr[right] >= pivot) {
            right--;
        }
        //走到这里说明此时arr[right]的数据小于pivot，填坑
        arr[left] = arr[right];
        left++;

        while (left < right && arr[left] <= pivot) {
            left++;
        }
        //走到这里说明此时arr[left]的数据大于pivot，填坑
        arr[right] = arr[left];
        right--;
    }
    //left等于right时，此时的位置就是pivot的位置
    arr[left] = pivot;

    //左区间为[begin,left-1]
    QuickSort(arr, begin, left - 1); //递归左区间

    //[right+1,end]
    QuickSort(arr, right + 1, end); //递归右区间
}


int main(int argc, char *argv[]) {
    QuickSort(&argc, 0, 10);
}
