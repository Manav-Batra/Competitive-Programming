  int percentageLetter(string s, char letter) {
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==letter)
            {
                ans++;
            }
        }
        int d=ans*100/s.length();
        return d;
    }
};