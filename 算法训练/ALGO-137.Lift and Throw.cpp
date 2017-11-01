#include <stdio.h>
#include <string.h>
#define max(a, b) a > b ? a : b
int x[4],l[4],t[4];                
int ans = 0;              
int w[4];                  //初始化为0，0表示可以进行操作，非零表示不可以
int p[4];                  //初始化为0，表示a[i]所举起的人
int a[4] = {3, 3, 3, 3};   //初始化为3，表人的状态，这里a对应的二进制为0011，后三位分别是三个动作：抛出，举起，移动。0（无意义）0（不可抛出）1（未进行举起）1（未进行移动）。这道题中，a只有六个可能值：0(0000)、1(0001)、2(0010)、3(0011)、4(0100)、5(0101)，表示人的六种状态
int near(int s){
    for (int i=1; i <= 3; i++)
        if (s == x[i] + 1 || s == x[i] - 1)return 1;
    return 0;
}
void dfs(int d){
    int j = 1, e = 0;
    for (int i=1; i <= 3; i++)ans = max(ans, x[i]);
    for (i = 1; i <= 3; i++){
        if (w[i])continue;	//不能进行操作 
        if ((a[i] & 1) && !(a[i] & 4))	//（未进行移动且不可抛出）
            for (j = 1; j <= l[i]; j++){
                x[i] += j;                                      //a[i]向前移动j
                a[i] ^= 1;                                      //已移动
                if (near(x[i]) || j == l[i])dfs(d + 1);
                x[i] -= j;                                      //归位
                x[i] -= j;                                      //a[i]向后移动j
                if (near(x[i]) || j == l[i])dfs(d + 1);
                x[i] += j;                                      //归位
                a[i] ^= 1;                                      //还原为未移动
            }
        if (a[i] & 2)//（未进行举起）
            for (j = 1; j <= 3; j++)                            //举起
                if (i != j && !w[j] && t[i] > 0)                //是否可以进行操作
                    if (x[i] == x[j] + 1 || x[j] == x[i] + 1){
                        w[j] = 1;                               //即将举起（抛出）j，抛出前将j是否可操作标记变更为否
                        a[i] ^= 2;                              //已举起
                        a[i] ^= 4;                              //可抛出
                        p[i] = j;                               //记录a[i]举起（抛出）了j
                        e = x[j];                               //记录a[j]的举起前位置
                        x[j] = -j;                              //a[j]（被举起）的位置定为负数，只作用于下一层递归时的取最远位置的循环
                        dfs(d + 1);
                        x[j] = e;                               //归位
                        w[j] = 0;                               //还原为可以进行操作
                        a[i] ^= 2;                              //还原为未举起
                        a[i] ^= 4;                              //还原为不可抛出
                    }
        if (a[i] & 4)//a[i] == 4 || a[i] == 5（可抛出）
            for (j = 1; j <= t[i]; j++){
                w[p[i]] = 0;                                    //变更a[j]为可操作（以下a[j]指a[i]所举起的人）
                a[i] ^= 4;                                      //不可抛出
                e = x[p[i]];                                    //记录a[j]被举起前位置
                x[p[i]] = x[i] + j;                             //抛出a[j]，并更新a[j]位置
                if (near(x[p[i]]) || j == t[i]) dfs(d + 1);
                x[p[i]] -= j;                                   //归位
                x[p[i]] -= j;                                   //a[j]向后抛出j
                if (near(x[p[i]]) || j == t[i]) dfs(d + 1);
                x[p[i]] = e;                                    //还原a[j]为未举起前的位置
                a[i] ^= 4;                                      //还原a[j]为可抛出
                w[p[i]] = 1;                                    //还原a[j]为不可操作
            }
    }
}

int main(){
    int i = 1;
    for (; i <= 3; i++)scanf("%d %d %d", &x[i], &l[i], &t[i]);
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
