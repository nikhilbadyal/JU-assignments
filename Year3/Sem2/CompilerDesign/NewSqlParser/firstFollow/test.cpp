#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <stack>

using namespace std;




void find_follow(vector< pair<string , vector<string>> >& gram, map< string, set<string> > &follows, map< string, set<string> > firsts, string non_term, set<string>& terms) {

    // cout<<"Finding follow of "<<non_term<<"\n";
    //cout<<"Got : "<<non_term<<endl;

    for(auto it = gram.begin(); it != gram.end(); ++it) {
        //cout<<"in bigger loop"<<endl;

        // finished is true when finding follow from this production is complete
        bool finished = true;
        auto ch = it->second.begin();

        // Skip variables till reqd non terminal
        for(;ch != it->second.end() ; ++ch) {
            //cout<<"First loop"<<endl;
            if(*ch == non_term) {
                //cout<<"found : "<<non_term<<endl;
                finished = false;
                break;
            }
        }
        ++ch;

        for(;ch != it->second.end() && !finished; ++ch) {
            // If non terminal, just append to follow
            if(terms.find(*ch) != terms.end()) {
                follows[non_term].insert(*ch);
                finished = true;
                break;
            }

            set<string> firsts_copy(firsts[*ch]);
            // If char's firsts doesnt have epsilon follow search is over
            if(firsts_copy.find("e") == firsts_copy.end()) {
                follows[non_term].insert(firsts_copy.begin(), firsts_copy.end());
                finished = true;
                break;
            }
            // Else next char has to be checked after appending firsts to follow
            firsts_copy.erase("e");
            follows[non_term].insert(firsts_copy.begin(), firsts_copy.end());
        }


        // If end of production, follow same as follow of variable
        if(ch == it->second.end() && !finished) {
            // Find follow if it doesn't have
            if(follows[it->first].empty()) {
                find_follow(gram, follows, firsts, it->first, terms);
            }
            follows[non_term].insert(follows[it->first].begin(), follows[it->first].end());
        }

    }

}


void find_first(vector< pair<string, vector<string>> >& gram, map< string, set<string> > &firsts, string curr_non_term, set<string>& terms) {

    // cout<<"Finding firsts of "<<non_term<<"\n";
    
    for(auto it = gram.begin(); it != gram.end(); ++it) {
    // Find productions of the non terminal
        if(it->first != curr_non_term) {
            continue;
        }
        
        //cout<<"Processing production "<<it->first<<"->"<<"\n";
        
        vector<string> rhs = it->second;
        // Loop till a non terminal or no epsilon variable found
        for(auto ch = rhs.begin(); ch != rhs.end(); ++ch) {
            // If first char in production a non term, add it to firsts list
            //cout<<*ch<<endl;
            if(terms.find(*ch) != terms.end() || ( (*ch) == "e")) {
                firsts[curr_non_term].insert(*ch);
                //cout<<"Terminal found\n";
                break;
            }
            else {
                // If char in prod is non terminal and whose firsts has no yet been found out
                // Find first for that non terminal
                if(firsts[*ch].empty()) {
                    find_first(gram, firsts, *ch, terms);
                //cout<<"First if\n";
                }
            // If variable doesn't have epsilon, stop loop (putting epsillon case)
            if(firsts[*ch].find("e") == firsts[*ch].end()) {
                firsts[curr_non_term].insert(firsts[*ch].begin(), firsts[*ch].end());
                //cout<<"Second if\n";
                break;
            }
            
            set<string> firsts_copy(firsts[*ch].begin(), firsts[*ch].end());
        
            // Remove epsilon from firsts if not the last variable
            if(ch + 1 != rhs.end()) {
                firsts_copy.erase("e");
            //cout<<"Removing epsilon\n";
            }

            // Append firsts of that variable
            firsts[curr_non_term].insert(firsts_copy.begin(), firsts_copy.end());
            }
        }
    //cout<<"Out Processing production "<<it->first<<"\n";

    }
}


int main()
{

    fstream grammar_file;
    grammar_file.open("gram3.txt", ios::in);
    if(!grammar_file.is_open()) {
        cout<<"Error in opening grammar file\n";
        return 2;
    }

    cout<<"Grammar parsed from grammar file: \n";
    int count = 0;
    string s;
    vector< pair<string, vector<string>> > gram;

    while(getline(grammar_file, s)) {
        vector<string>v_temp;
        string temp = "";
        int i = 0 ;
        while(i < s.size()){
            while(i<s.size() && s[i] == ' '){
                i++;
            }
            temp = "";
            while(i<s.size() && s[i] != ' '){
                temp = temp + s[i];
                i++;
            }
            //cout<<"Adding : "<<temp<<endl;
            v_temp.push_back(temp);
        }

        string key = v_temp[0];
        vector<string> value;


        for(int i=2;i<v_temp.size();i++){
            //cout<<"Putting  : "<<v_temp[i]<<endl;
            value.push_back(v_temp[i]);
        }

        //cout<<value<<endl;

        gram.push_back({key, value});
        cout<<count<<".  "<<gram.back().first<<" -> ";
        for(int i=0;i<gram.back().second.size();i++){
            cout<<gram.back().second[i]<<" ";
        }cout<<"\n";

        count++;
    }
    cout<<"\n";


    cout<<"\n";


    // Gather all non terminals
    set<string> non_terms;
    for(auto i = gram.begin(); i != gram.end(); ++i) {
        non_terms.insert(i->first);
    }

    cout<<"The non terminals in the grammar are: ";
    for(auto i = non_terms.begin(); i != non_terms.end(); ++i) {
        cout<<*i<<" ";
    }
    cout<<"\n";
    // Gather all terminals
    set<string> terms;
    for(auto i = gram.begin(); i != gram.end(); ++i) {
        for(auto ch = i->second.begin(); ch != i->second.end(); ++ch) {
            string s = *ch;
            bool terminal = true;

            //cout<<s<<endl;
            for(int i=0;i<s.size();i++){
                //cout<<s[i]<<endl;
                if(isupper(s[i])){
                    //cout<<"in :"<<endl;
                    terminal = false;
                }
            }

            if(terminal){
                terms.insert(s);
            }
        }
    }


    // Remove epsilon and add end character $
    terms.erase("e");
    terms.insert("$");
    cout<<"The terminals in the grammar are: ";
    for(auto i = terms.begin(); i != terms.end(); ++i) {
        cout<<*i<<" ";
    }
    cout<<"\n\n";


    string start_sym = gram.begin()->first;


    map< string, set<string> > firsts;
    for(auto non_term = non_terms.begin(); non_term != non_terms.end(); ++non_term) {
        if(firsts[*non_term].empty()){
            //cout<<"Sending "<<*non_term<<endl;
            find_first(gram, firsts, *non_term, terms);
        }
    }

    firsts.erase("e");
    cout<<"Firsts list: \n\n";
    for(auto it = firsts.begin(); it != firsts.end(); ++it) {
        cout<<it->first<<" -> ";
        for(auto firsts_it = it->second.begin(); firsts_it != it->second.end(); ++firsts_it) {
            cout<<*firsts_it<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n";

    map< string, set<string> > follows;
    // Find follow of start variable first
    string start_var = gram.begin()->first;
    follows[start_var].insert("$");
    find_follow(gram, follows, firsts, start_var, terms);
    // Find follows for rest of variables
    for(auto it = non_terms.begin(); it != non_terms.end(); ++it) {
        if(follows[*it].empty()) {
            find_follow(gram, follows, firsts, *it, terms);
        }
    }

    cout<<"Follows list: \n";
    for(auto it = follows.begin(); it != follows.end(); ++it) {
        cout<<it->first<<" : ";
        for(auto follows_it = it->second.begin(); follows_it != it->second.end(); ++follows_it) {
            cout<<*follows_it<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";


    int parse_table[non_terms.size()][terms.size()];
    fill(&parse_table[0][0], &parse_table[0][0] + sizeof(parse_table)/sizeof(parse_table[0][0]), -1);

    for(auto prod = gram.begin(); prod != gram.end(); ++prod) {
        vector<string> rhs = prod->second;

        set<string> next_list;
        bool finished = false;
        for(auto ch = rhs.begin(); ch != rhs.end(); ++ch) {
            if(terms.find(*ch) != terms.end()) {
                if(*ch != "e") {
                    next_list.insert(*ch);
                    finished = true;
                    break;
                }
                continue;
            }

            set<string> firsts_copy(firsts[*ch].begin(), firsts[*ch].end());
            if(firsts_copy.find("e") == firsts_copy.end()) {
                next_list.insert(firsts_copy.begin(), firsts_copy.end());
                finished = true;
                break;
            }
            firsts_copy.erase("e");
            next_list.insert(firsts_copy.begin(), firsts_copy.end());
        }
        // If the whole rhs can be skipped through epsilon or reaching the end
        // Add follow to next list
        if(!finished) {
            next_list.insert(follows[prod->first].begin(), follows[prod->first].end());
        }


        for(auto ch = next_list.begin(); ch != next_list.end(); ++ch) {
            int row = distance(non_terms.begin(), non_terms.find(prod->first));
            int col = distance(terms.begin(), terms.find(*ch));
            int prod_num = distance(gram.begin(), prod);
            if(parse_table[row][col] != -1) {
                cout<<"Collision at ["<<row<<"]["<<col<<"] for production "<<prod_num<<"\n";
                continue;
            }
            parse_table[row][col] = prod_num;
        }

    }
    // Print parse table
    cout<<"Parsing Table: \n";
    cout<<"   ";
    for(auto i = terms.begin(); i != terms.end(); ++i) {
        cout<<*i<<" ";
    }
    cout<<"\n";
    for(auto row = non_terms.begin(); row != non_terms.end(); ++row) {
        cout<<*row<<"  ";
        for(int col = 0; col < terms.size(); ++col) {
            int row_num = distance(non_terms.begin(), row);
            if(parse_table[row_num][col] == -1) {
                cout<<"- ";
                continue;
            }
            cout<<parse_table[row_num][col]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    
    vector<string> input = {"select"};
    vector<string> input_string = input;
    input_string.push_back("$");
    stack<string> st;
    st.push("$");
    st.push("S");

    // Check if input string is valid
    for(auto ch = input_string.begin(); ch != input_string.end(); ++ch) {
        if(terms.find(*ch) == terms.end()) {
            cout<<"Input string is invalid\n";
            return 2;
        }
    }

    // cout<<"Processing input string\n";
    bool accepted = true;
    while(!st.empty() && !input_string.empty()) {
        // If stack top same as input string char remove it

        if(input_string[0] == st.top()) {
            st.pop();
            input_string.erase(input_string.begin());
        }
            //if non terminal found but lookhead doesn't match
        else if(terms.find(st.top()) != terms.end()) {
            cout<<"Unmatched terminal found\n";
            accepted = false;
            break;
        }
        else {
            string stack_top = st.top();
            int row = distance(non_terms.begin(), non_terms.find(stack_top));
            int col = distance(terms.begin(), terms.find(input_string[0]));
            int prod_num = parse_table[row][col];

            if(prod_num == -1) {
                cout<<"No production found in parse table\n";
                accepted = false;
                break;
            }

            st.pop();
            vector<string> rhs = gram[prod_num].second;
            if(rhs[0] == "e") {
                continue;
            }
            for(auto ch = rhs.rbegin(); ch != rhs.rend(); ++ch) {
                st.push(*ch);
            }
        }
    }

    if(accepted) {
        cout<<"Input string is accepted\n";
    }
    else {
        cout<<"Input string is rejected\n";
    }
    return  0;
}