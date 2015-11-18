class Solution {
public:
    /*
    awesome solution using strtol(const char *nptr,char **endptr,int base);
    but still doesn't consider the overflow
    by the way, fuck the other solutions using multiply method without considering overflow
    */

    int compareVersion(string version1, string version2) {
        int ret = 0;

        char* vStr1 = (char*)version1.c_str();
        char* vStr2 = (char*)version2.c_str();
        
        while(ret == 0 && (*vStr1 != '\0' || *vStr2 != '\0'))
        {
            
            long v1 = *vStr1 == '\0' ? 0 : strtol(vStr1, &vStr1, 10);
            long v2 = *vStr2 == '\0' ? 0 : strtol(vStr2, &vStr2, 10);
            if(v1 > v2)
                ret = 1;
            else if(v1 < v2)
                ret = -1;
            else
            {
                if(*vStr1 != '\0')
                    vStr1++;
                if(*vStr2 != '\0')
                    vStr2++;
            }
        }
        
        return ret;
        
    }
};