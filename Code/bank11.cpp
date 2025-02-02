    while (getline(fin, line))
    {

        if (line == "Account Number: " + to_string(accountNumber1))
        {
            cout<<"Account number is found"<<endl;
            char ch;
           
            char c = fin.tellg();
            cout<<"c :"<<c<<endl;
            fin.seekg(8, ios::cur);
            char d = fin.tellg();
            cout<<"d :"<<d<<endl;
            //int i = 0;
            while (ch != '\n')
            {
                ch = fin.get();
                cout<<ch;
                //numStr[i] = ch; 
                //i++; 
               
            }
            // int num = atoi(numStr);
            // cout<<"The balance is: "<<num;
            // result = result + amount;
            // cout << "Balance:" << result;
            // cout << "Amount deposite successfully.";
            exit(0);
        }
    }