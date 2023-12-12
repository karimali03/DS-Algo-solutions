class trie {
private:
	map<char,trie*>child;
	// List of indices of prefixes inserted here
	vector<int> indices;

public:
	trie() {
	}

	void insert(const string &str, int word_idx) {
		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			char ch = str[idx];
			if (!cur->child.count(ch))
			cur->child[ch] = new trie();
			cur->child[ch]->indices.push_back(word_idx);
			cur = cur->child[ch];
		}
	}

	vector<int> get_positions(const string &str) {
		vector<int> positions;
		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			char ch = str[idx];
			if (!cur->child.count(ch)  )
				return {};
			cur = cur->child[ch];
		}
		return cur->indices;	
	}
};

class WordFilter {
public:
	trie t;

	WordFilter(vector<string>& words) {
		set<string> words_set;

		for (int i = words.size()-1; i >=0; --i) {
			if (words_set.insert(words[i]).second) {
				for(int j=0;j<words[i].size();j++){
         string key=
     words[i].substr(j,words[i].size()-j)+"#"+words[i];
          t.insert(key,i);
                }
			}
		}
	}

	int f(string prefix, string suffix) {
        string key=suffix+"#"+prefix;
        vector<int>indces=t.get_positions(key);
        if(indces.empty()) return -1;
        return indces[0];
	}
};