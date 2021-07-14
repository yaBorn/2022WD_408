//======================================== p13 顺序表 内存分配与结构体
/* 静态分配 */
typedef struct {
    ElemType data[maxSize]; // 元素
    int length;             // 当前长度
}sqList;                    // 类型名

/* 动态分配 */
typedef struct {
    ElemType *data;         // 指针
    int maxSize, length;
}sqList;

/* c动态分配 */
L.data = (ElemType*) malloc(sizeof(ElemType) * InitSize);

/* c++动态分配 */
L.data = new ElemType[InitSize];

//======================================== p14 顺序表基本操作
/* 插入 */
// 第i位置（i-1下标）插入
bool ListInsert (sqList &L, int i, ElemType e) {
    // 判断插入位置i合法
    if (i<1 || i>L.length+1)
        return false;
    // 判断顺序表是否满载
    if (L.length >= maxSize)
        return false;
    // 将 第i个元素 及 之后的元素后移
    for (int j=L.length; j>=i; j--)
        L.data[j] = L.data[j-1];    // length为长度（从1开始），数组下标（从0开始）
    // 第i位置赋值e
    L.data[i-1] = e;
    // 表长+1
    L.length++;
    return true;
}

/* 删除 */
// 删除第i位置，返回给e
bool ListDelete (sqList &L, int i, ElemType &e) {
    // 判断i合法
    if (i<1 || i>L.length)
        return false;
    // 删除元素赋值e
    e = L.data[i-1];
    // 第i位置后面的元素前移
    for(int j=i; j<L.length; j++)
        L.data[j] = L.data[j+1];
    // 表长-1
    L.length--;
    return true;
}

/* 按值查找 */
// 在顺序表中查找第一个值为e的元素，返回位序(从1开始为位序)
int LocalElem (sqList &L, ElemType e) {
    for(int i=0; i<L.length; i++)   // 遍历顺序表
        if(L.data[i]==e)            // 找到等于的元素
            return ++i;             // 返回i+1
    return 0;
}
