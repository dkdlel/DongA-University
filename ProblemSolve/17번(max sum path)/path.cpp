//
//  path.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/04/23.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/path.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/path.out");

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

Node *CreateNode(int data){
    Node *node = new(struct Node);
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
Node *tree; // 전체 트리 생성
int node_num; // 노드의 개수
vector<int> weight, preorder;
int result;
void Init(){
    result = -987654321;
    fcin >> node_num;
    weight.resize(node_num); preorder.resize(node_num);
    for(int i = 0 ; i < node_num ; i++){
        fcin >> weight[i];
    }
    for(int i = 0 ; i < node_num ; i++){
        fcin >> preorder[i];
    }
    tree = CreateNode(weight[preorder[0]]);
}
void MakeTree(Node *root, int preroot, int left, int right){ // preroot : 부모트리의 정보(preorder를 계산하기위한 정보)
    if(left <= right){
        int sub_left = preorder[preroot] - left;
        int sub_right = right - preorder[preroot];
        if(sub_left > 0){ // 왼쪽 자식이 더 있으면
            root -> left = CreateNode(weight[preorder[preroot + 1]]);
            MakeTree(root->left, preroot+1, left, preorder[preroot] -1); // preorder+1을 통해 다음 root를 갱신하고, left는 그대로, right는 이전 root의 -1
        }
        if(sub_right > 0){ // 오른쪽 자식이 더 있으면
            root ->right = CreateNode(weight[preorder[preroot + sub_left + 1]]);
            MakeTree(root->right, preroot + sub_left + 1, preorder[preroot] + 1, right); // 오른쪽 이니까 root는 왼쪽 서브트리의 합 + 1을 통해 다음 root를 갱신하고, left는 이전 rootdml +1, right는 그대로
        }
    }
}
int SumPath(Node *root){

    if(root == NULL) return 0; // 빈 노드
    
    if(root->left == NULL && root->right == NULL) { // 자식이없는 노드(leaf node)
        result = max(result, root->data);
        return root->data;
    }
    
    int leftsum = SumPath(root->left); // 왼쪽 서브트리의 최대 합
    int rightsum = SumPath(root->right); // 오른쪽 서브트리의 최대 합
    
    if(root->left && root->right){ // 자식이 둘다 있을 경우
        result = max(result, leftsum + rightsum + root->data);
        return max(leftsum, rightsum) + root->data;
    }
    return (root->left == NULL) ? rightsum + root->data : leftsum + root->data; // 자식이 둘중 하나만 있을 경우
}
int main(){
    
    int testcase;
    fcin >> testcase;
    while(testcase--){
        Init();
        MakeTree(tree, 0, 0, node_num-1);
        SumPath(tree);
        fcout << result << '\n';
    }

    return 0;
}
