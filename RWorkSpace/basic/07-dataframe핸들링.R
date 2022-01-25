# data.frame 핸들링
# 새로운 변수 만들기 : 데이터프레임$변수명 또는 데이터프레임['변수명'] <- 추가할 데이터 벡터
# 조건으로 선택 : subset(x, subset=(조건))  #subset=생략가능
# 목록으로 선택 : subset(x, subset=(조건), select=열/열 목록)
# 열, 열 목록 제거 : subset(x, subset=(조건), selcet=-열/-열 목록)
# 열 이름 바꾸기 : colnames(x) <-, colnames(x)[index] <-


rm(list=ls())
df = read.csv('basic\\data\\easySample3.csv', fileEncoding = "UTF-8-BOM")
df1 = df[, c(2, 4, 6, 8)]  #데이터 col 선택
df1$score = c(90, 80, 50, 70, 100, 95, 85, 70, 95, 75)  #데이터 입력
df2 = subset(df1, subset=(salary>=5000))  #조건걸기
df3 = subset(df2, select=-score)  #데이터 제외
df4 = subset(df1, subset=(salary>=5000), select=-score)
df5 = subset(df2, select= c(pname, dept, salary))
colnames(df5)[2] = 'department'  #colname 변경