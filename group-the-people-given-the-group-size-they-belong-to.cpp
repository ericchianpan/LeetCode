class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mappingTable;
         vector<vector<int>> ans;
         for(int i = 0; i < groupSizes.size(); ++i) {
            int groupSize = groupSizes[i];
            // if(mappingTable.find(groupSize) == mappingTable.end()) mappingTable.insert(make_pair(groupSize, vector<int>{}));
            mappingTable[groupSize].push_back(i);
            if(mappingTable[groupSize].size() >= groupSize) {
                ans.push_back(vector<int>(mappingTable[groupSize].begin(), mappingTable[groupSize].end()));
                mappingTable[groupSize].clear();
            }
        }
        return ans;
    }
};
