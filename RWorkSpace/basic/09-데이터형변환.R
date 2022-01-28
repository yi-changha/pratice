rm(list=ls())
r1 = as.integer(3.14) # 소수점 아래 절삭
r2 = as.numeric('abc') # 수치로 바꿀 수 없는 것을 넣으면 NA 
r3 = as.numeric(TRUE) # 1  FALSE=0
r4 = as.logical(0.1) # TRUE

rm(list=ls())
r1 = as.Date('2021-5-01')
#r2 = as.Date('03/14/2021')  # Error
r3 = as.Date('03/14/2021', format= '%m/%d/%Y')
r4 = format(Sys.Date())
r5 = format(Sys.Date(), format='%m/%d/%Y')

rm(list=ls())
r1 = format(Sys.Date(), '%a') #요일
r2 = format(Sys.Date(), '%b') #월
r3 = format(Sys.Date(), '%y') #22
r4 = format(Sys.Date(), '%Y') #2022