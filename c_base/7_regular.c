#include <stdio.h>
#include <regex.h>

int main() {
    const char *pattern = "^[a-zA-Z]+$"; // 匹配仅包含字母的字符串
    const char *test_string = "HelloWorld";
    regex_t regex;
    int ret;

    // 编译正则表达式
    ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret) {
        fprintf(stderr, "无法编译正则表达式\n");
        return 1;
    }

    // 执行正则表达式匹配
    ret = regexec(&regex, test_string, 0, NULL, 0);
    if (!ret) {
        printf("匹配成功\n");
    } else if (ret == REG_NOMATCH) {
        printf("不匹配\n");
    } else {
        char error_message[100];
        regerror(ret, &regex, error_message, sizeof(error_message));
        fprintf(stderr, "正则表达式匹配错误: %s\n", error_message);
        return 1;
    }

    // 释放正则表达式结构
    regfree(&regex);

    return 0;
}
