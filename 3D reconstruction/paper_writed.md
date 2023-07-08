# mvs
## unimvsnet
1. 将深度估计换了一种表示方法(深度平面分类问题+偏移值回归问题)
2. 利用focal loss的变形对分类和回归问题进行统一损失处理  
result:0.352 0.278 0.315
## casmvsnet
1. 采用FPN级联结构进行有粗到细的生成深度图(节省内存和时间）
2. 每一阶段的深度图为下一阶段的深度平面范围（d-△d，d+△d）
result:0.325 0.385 0.355
## itermvs
1.利用gru来代替3dcnn正则化
result:
## transmvsnet
1. 将深度估计问题转位特征匹配问题
