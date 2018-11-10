//给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点(i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为(i, ai) 和(i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//说明：你不能倾斜容器，且 n 的值至少为 2。
//
//图中垂直线代表输入数组[1, 8, 6, 2, 5, 4, 8, 3, 7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
//
//示例 :
//输入 : [1, 8, 6, 2, 5, 4, 8, 3, 7]
//输出 : 49

#include<stdio.h>
#include<Windows.h>

int maxArea(int* height, int heightSize) {
	int i = 0;
	int j = 0;
	int max = 0;
	for (i = 0; i < heightSize; i++)
	{
		for (j = i + 1; j < heightSize; j++)
		{
			int ret = height[i]>height[j] ? (height[j]*(j - i)) : (height[i]*(j - i));
			if (ret >= max)
				max = ret;
		}
	}
	return max;
}

int main()
{
	int height[] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	int heightSize = sizeof(height) / sizeof(height[0]);
	int ret = maxArea(height, heightSize);
	printf("%d ", ret);
	system("pause");
	return 0;
}

//我们在由线段长度构成的数组中使用两个指针，一个放在开始，一个置于末尾。 
//此外，我们会使用变量 maxarea 来持续存储到目前为止所获得的最大面积。 
//在每一步中，我们会找出指针所指向的两条线段形成的区域，更新 maxarea，
//并将指向较短线段的指针向较长线段那端移动一步