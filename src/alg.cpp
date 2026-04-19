// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return 0;
}

std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> st;
    std::string result;
    for (size_t i = 0; i < inf.size(); i++) {
        char c = inf[i];
        if (isdigit(c)) {
            while (i < inf.size() && isdigit(inf[i])) {
                result += inf[i];
                i++;
            }
            result += ' ';
            i--;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                result += ' ';
                st.pop();
            }
            st.pop();
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!st.empty() && priority(st.top()) >= priority(c)) {
                result += st.top();
                result += ' ';
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        result += ' ';
        st.pop();
    }
    return result;
}

int eval(const std::string& pref) {
    TStack<int, 100> st;
    for (size_t i = 0; i < post.size(); i++) {
        if (post[i] == ' ') continue;
        if (isdigit(post[i])) {
            int num = 0;
            while (i < post.size() && isdigit(post[i])) {
                num = num * 10 + (post[i] - '0');
                i++;
            }
            st.push(num);
            i--;
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int res = 0;
            if (post[i] == '+') res = a + b;
            else if (post[i] == '-') res = a - b;
            else if (post[i] == '*') res = a * b;
            else if (post[i] == '/') res = a / b;
            st.push(res);
        }
    }
    return st.top();
}
