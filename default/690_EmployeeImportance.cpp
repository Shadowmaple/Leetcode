# include <iostream>
# include <vector>
# include <map>
# include <queue>
using namespace std;

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> mp;
        for (int i = 0; i < employees.size(); i++) {
            mp[employees[i]->id] = employees[i];
        }

        int matter = 0;
        queue<Employee*> q;
        q.push(mp[id]);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            matter += cur->importance;
            for (auto s : cur->subordinates) {
                q.push(mp[s]);
            }
        }
        return matter;
    }
};