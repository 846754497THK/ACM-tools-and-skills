/*
    枚举子集
*/
// ===================================================
for (int i = 1; i < all; i++)
    for (int j = i; j; j = i & (j - 1))
// ===================================================