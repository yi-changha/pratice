# 외부 데이터 사용

# 작업환경 설정
# setwd('디렉터리 이름')
# getwd() : 현재 작업 디렉터리 이름 반환

# csv 파일 불러오기, 저장하기
# read.csv('파일이름', fileEncoding='UTF-8-BOM')
# write.csv('파일이름', row.names=FALSE)
# row.names=FALSE : 저장하지 않음.

rm(list=ls())
df = read.csv('basic\\data\\easySample.csv', fileEncoding = "UTF-8-BOM")
print(df)
write.csv(df, 'basic/data/mySample.csv', row.names = FALSE)
write.csv(df, 'basic/data/mySample_wr.csv', row.names = TRUE)


rm(list=ls())
cname = c('ID', 'name', 'birth', 'dept', 'english', 'japanese', 'chinese')
df3 = read.table('basic/data/easySample.txt', sep=',' ,col.names = cname)
# sep=',' sep이 ,로 되어있다고 알려줘야함
print(df3)


rm(list=ls())
df4 = read.csv('basic/data/mySample.csv')
save(df4, file='basic/data/myObject1.Rdata')
rm(list=ls())
ls()
load('basic/data/myObject1.Rdata')
print(df4)