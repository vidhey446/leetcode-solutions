char st[10000];
int top = -1;

// CHANGED: Function declarations added before isValid()
void push(char c);
bool pop(void);
char peek(void);

bool isValid(char* s) {

    top = -1;

    for(int i = 0; s[i] != '\0'; i++) {

        // s[i] is the current character

        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {

            push(s[i]);

        } 
        else if (s[i] == ')') {

            if(top == -1)
                return false;

            if(peek() == '(') {
                pop();
            } 
            else {
                return false;
            }

        } 
        else if (s[i] == ']') {

            if(top == -1)
                return false;

            if(peek() == '[') {
                pop();
            } 
            else {
                return false;
            }

        } 
        else if (s[i] == '}') {

            if(top == -1)
                return false;

            if(peek() == '{') {
                pop();
            } 
            else {
                return false;
            }
        }
    }

    if(top == -1) {
        return true;
    }

    return false;
}


void push(char c) {

    if(top == 9999) {
        return;
    }

    st[++top] = c;
}


bool pop(void) {

    if(top == -1) {
        return false;
    }

    top--;

    return true;       // CHANGED: return value added
}


char peek(void) {

    // CHANGED: Since isValid() checks top != -1 before peek(),
    // this is safe.
    return st[top];
}

