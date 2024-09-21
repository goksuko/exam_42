#include <string.h>
#include <unistd.h>

int validate_html(const char *html) {
    char stack[1000][1000];  // Fixed-size stack for storing tags
    int top = -1;           // Stack pointer
    int i = 0;              // Index for traversing the input string

    while (html[i]) {
        if (html[i++] == '<') {  // Find the opening '<'
            char tag[100];  // Temporary storage for the current tag
            int j = 0;

            // Read until closing '>' or end of tag name
            while (html[i] && html[i] != '>' && j < 999) {
                tag[j++] = html[i++];
            }
            tag[j] = '\0';

            if (html[i] != '>') {
                return 1; // Error if '>' is missing
            }
            i++; // Skip the closing '>'

            if (tag[0] == '/') {  // Closing tag
                if (top < 0 || strncmp(stack[top], tag + 1, strlen(stack[top]) + 1) != 0) {
                    return 1; // Mismatched closing tag
                }
                top--; // Pop from stack
            } else if (strncmp(tag, "img", 3) != 0 || (tag[3] != '\0' && tag[3] != ' ')) {
                // Not a self-closing <img> tag, push to stack
                strncpy(stack[++top], tag, 999);  // Push to stack
                stack[top][999] = '\0';           // Ensure null-termination
            }
        }
    }

    // Return 0 if stack is empty, 1 otherwise
    if (top == -1) {
        return 0;
    } else {
        return 1;
    }
}


int main(int argc, char *argv[]) {
    if (argc != 2) 
		return (write(1, "1\n", 2), 1);
    char r = validate_html(argv[1]) + '0';
    write(1, &r, 1);
    write(1, "\n", 1);
    return r - '0';
}