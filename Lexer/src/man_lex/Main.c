#include "Main.h"
/**
 * @author: 丁志鹏(OliverDD)
 * @email: oliverdd@std.uestc.edu.cn
 * @date: 2019.10.10
 * @purpose: Java词法分析器手动实现
 * @todo:
 *            1. 预处理： 消除注释(单行注释与多行注释)与空白字符(换行，制表与空格)
 *            2. 词法分析： 具体参看Lexical
 */
int main(int argc, char *argv[]){
#ifdef LOCAL
    logcat("LEXER: 开始执行");
#endif
    argc--;
    argv++;
    if(argc == 0){
        printf("\33[31mLEXER:无输入文件\n\33[31m");
        return 1;
    }else{
        while(argc > 0){
            /* 预处理 */
            if(preprocessor(argv[0]) == 1){
                printf("\33[31mLEXER: 处理文件%s时出错\n\33[31m", argv[0]);
                argc--;
                argv++;
                continue;
            }
            /* 预处理结束 */
            lexical_analysis(argv[0]);
            argc--;
            argv++;
        }
    }
#ifdef LOCAL
    logcat("LEXER: 执行成功");
#endif
    return 0;
}
