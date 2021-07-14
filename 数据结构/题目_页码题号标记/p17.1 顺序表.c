/* 1 */
ElemType func_deleteMin (sqList &L) {
    // 检查表空
    if (L.length <= 0)
        return 0;
    
    ElemType e = L.data[0]; // 当前最小元素（初试取第一个）
    int minID = 0;            //最小元素的下标
    // 找到最小值
    for (int i=1; i<L.length; i++)        // 遍历顺序表（从下标1开始）
        if (e.data > L.data[i].data) {    // 若e>遍历元素，元素赋值给e
            e = L.data[i];
            minID = i;
        }
    // 最后一位填补min位置
    L.data[minID] = L.data[L.length-1];
    L.length--; // 表长-1
    return e;
}

/* 2 */