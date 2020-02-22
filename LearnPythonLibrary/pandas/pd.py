#
# pd.py
#

import numpy as np
import pandas as pd


# s = pd.Series([1,3,6,np.nan,44,1])
# print(s)


dates = pd.date_range('20160101',periods=6)
# print(dates)
df = pd.DataFrame(np.random.rand(6,4),index=dates,columns=['a','b','c','d'])
print(df)
# print(df['a'])
# print(df.loc['20160103'])
print(df.iloc[[1,2],1:2])
