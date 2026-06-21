class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;

        for(const string &op:operations){
        if(op=="+"){
            int num1=record[record.size()-1];
            int num2=record[record.size()-2];
            record.push_back(num1+num2);
        }else if(op=="C"){
            record.pop_back();
        }else if(op=="D"){
            int topp=record.back();
            record.push_back(2*topp);
        }else{
            record.push_back(stoi(op));
        }
        }
        int totalsum=0;
        for(int rec:record){
            totalsum+=rec;
        }
        return totalsum;
    
    }
};