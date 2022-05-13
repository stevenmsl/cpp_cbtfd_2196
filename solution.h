
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol2196
{

  class Solution
  {
  private:
    Node *_build(int val, unordered_map<int, pair<int, int>> children);

  public:
    Node *build(vector<vector<int>> &desp);
  };
}
#endif