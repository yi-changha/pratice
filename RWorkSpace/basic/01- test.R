rm(list=ls())   # rm :삭제
ls()
a <- 10         # 대입
b = 20          # 대입
hap = a + b
cat(a, '+', b, '=', hap, "\n")  # 여러 개 출력
ls()            # "a" "b" "hap"
rm(hap)
ls()            # "a" "b"
a_list = 10
a.so = 20
#1abc = 30       # 숫자가 앞으로 가면 에러
