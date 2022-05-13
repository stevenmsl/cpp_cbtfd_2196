#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol2196;

/*
Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
*/

tuple<vector<vector<int>>, Node *>
testFixture1()
{
  auto desp = vector<vector<int>>{
      {20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
  auto root = new Node(50);
  root->left = new Node(20);
  root->left->left = new Node(15);
  root->left->right = new Node(17);

  root->right = new Node(80);
  root->right->left = new Node(19);

  return make_tuple(desp, root);
}

/*
Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.
*/

tuple<vector<vector<int>>, Node *>
testFixture2()
{
  auto desp = vector<vector<int>>{
      {1, 2, 1}, {2, 3, 0}, {3, 4, 1}};
  auto root = new Node(1);
  root->left = new Node(2);
  root->left->right = new Node(3);
  root->left->right->left = new Node(4);

  return make_tuple(desp, root);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  auto root = sol.build(get<0>(f));
  cout << "Expect to see 50:" << root->val << endl;
  cout << "Expect to see 19:" << root->right->left->val << endl;
}

void test2()
{
  auto f = testFixture2();
  Solution sol;
  auto root = sol.build(get<0>(f));
  cout << "Expect to see 1:" << root->val << endl;
  cout << "Expect to see 4:" << root->left->right->left->val << endl;
}

main()
{
  test1();
  test2();
  return 0;
}