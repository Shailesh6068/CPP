    vector<vector<int>> v;
    v.push_back({12,32,45});
    v.push_back({14,54});
    v.push_back({34,56,78,90});

   // vector<vector<int>> :: iterator it;
    for (int i = 0; i < v.size(); i++)
    {  
       // vector<int>::iterator it;                                 // Declare iterator for the inner vector
        for (auto it = v[i].begin() ; it != v[i].end() ; it++)     //  when we write the auto there is not requirament
        {                                                          //  to write the vector<int> :: iterator it;
            cout<<*it<<" ";
        }
        cout<<endl;
    }

    cout<<"\n --- After insert --- \n"; 
    vector<vector<int>> :: iterator it;           // Declare iterator for the outer vector
    v.insert(it+1 , {45,75});
    for (int i = 0; i < v.size(); i++)
    {
        for (auto it = v[i].begin() ; it != v[i].end() ; it++)     
        {                                                          
            cout<<*it<<" ";
        }
        cout<<endl;
    }
