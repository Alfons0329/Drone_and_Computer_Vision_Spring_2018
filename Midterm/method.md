--------------------------待確認開始----------------------------------
1. 『看到』的時候能否讓他在接近畫面中央的位置，也許用rvec判斷，否則會飛歪，但應該也還好（？
--------------------------待確認結束----------------------------------
--------------------------unit test 確認能飛過1-------------------------------
1.飛起來 然後state = 0 自轉（順逆皆可） 看到id1 vx = 某 vy = (tvec[0][0] / tvec[0][2]) * vx
依據相似三角形的原理 此時繼續維持state 0
2.飛著飛著必然id1會不見 此時鏡頭會看左前方
```cpp
if(ids.size() == 0 && state == 0)
{
    vr = 某 (會希望能看到marker它會在水平方向盡量偏中間)
    if(flag1 == true)
    {
        state = 1 便可以跳離if
    }
}
```
3.
```cpp
if(state == 1 && tvec[0][2] > 100)也許可以舍更多區間讓它穩定一點
{
    vx = 某
}
else
{
    vx = 0
    state = 2 //成功抵達下一個目標的指定距離
}
```
--------------------------unit test 確認能飛過1-------------------------------
--------------------------unit test 確認能飛過2 3-------------------------------
```cpp
if(state == 2 && flag2 == false)
{
    vr = 某 持續旋轉直到在marker2的位置看到3
    if(flag2 == true)
    {
        state = 3 便可以跳離if
    }
}
```
```cpp
if(state == 3 && tvec[0][2] > 100)也許可以舍更多區間讓它穩定一點
{
    vx = 某
}
else
{
    vx = 0
    state = 4 //成功抵達下一個目標的指定距離
}
```
--------------------------unit test 確認能飛過2 3-------------------------------
--------------------------unit test 確認能飛回來-------------------------------
```cpp
if(state == 4 && flag3 == false)
{
    vr = 某 持續旋轉直到在marker2的位置看到3
    if(flag4 == true)
    {
        state = 5 便可以跳離if
    }
}

if(state == 5 && tvec[0][2] > 100)也許可以舍更多區間讓它穩定一點
{
    vx = 某
}
else
{
    ARDrone.landing();
}

```
--------------------------unit test 確認能飛回來-------------------------------