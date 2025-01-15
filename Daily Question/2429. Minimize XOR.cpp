class Solution {
    string reverse(string num){
        int n = num.length();
        int i = 0;
        int j = n-1;
        while(i<j){
            int t = num[i];
            num[i] = num[j];
            num[j] = t;
            i++;
            j--;
        }
        return num;
    }
    string to_binary(int num1){
        string ans = "";
        while(num1 > 0){
            ans += to_string(num1%2);
            num1 /= 2;
        }
        return reverse(ans);
    }
    int to_num(string num){
        int n = num.length();
        int number = 0;
        for(int i = n-1; i>=0; i--){
            number = number + (num[i]-'0')*pow(2,n-i-1);
        }
        return number;
    }
public:
    int minimizeXor(int num1, int num2) {
        string n1 = to_binary(num1);
        string n2 = to_binary(num2);
        int n1Ones = 0;
        int n2Ones = 0;
        for(int i = 0; i<n1.length();i++){
            if(n1[i] == '1') n1Ones++;
        }
        for(int i = 0; i<n2.length();i++){
            if(n2[i] == '1') n2Ones++;
        }
        int n1Len = n1.length();
        int n2Len = n2.length();
        if(n1Len > n2Len){
            int d = n1Len - n2Len;
            for(int i = 0; i<d; i++){
                n2 = '0' + n2;
            }
            n2Len = n1Len;
        }
        else{
            int d = n2Len - n1Len;
            for(int i = 0; i<d; i++){
                n1 = '0' + n1;
            }
            n1Len = n2Len;
        }
        
        if(n1Ones == n2Ones){
            return num1;
        }
        else if(n1Ones < n2Ones){
            for(int i = n1Len-1;i>=0; i--){
                if(n1Ones == n2Ones){
                    return to_num(n1);
                }
                if(n1[i] == '0'){
                   
                    n1[i] = '1';
                    
                    n1Ones++;
                }
            }
            if(n1Ones < n2Ones){
                while(n1Ones != n2Ones){
                    n1 = n1 + '1';
                    n1Ones++;
                }
            }
            if(n1Ones == n2Ones){
                    return to_num(n1);
                }
        }
        else{
            for(int i = n1Len-1;i>=0; i--){
                if(n1Ones == n2Ones){
                    return to_num(n1);
                }
                if(n1[i] == '1'){
                    n1[i] = '0';
                    n1Ones--;
                }
            }
            if(n1Ones == n2Ones){
                return to_num(n1);
            }
        }
        return num1;
    }
};
