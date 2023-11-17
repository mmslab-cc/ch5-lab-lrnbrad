#!/bin/bash
echo "Running tests..."
echo

# 加入輸入資料
output=$(echo 6 7 8 9 10 0  10 9 8 7 6 0  5 4 3 2 1 0  8 9 10 9 8 1 | ./a.out)

if [ $? -eq 0 ] ; then
  echo "Pass: Program exited zero"
else
  echo "Fail: Program did not exit zero"
  exit 1
fi

echo "$output"

echo
echo ">> 這次實驗沒有自動評分，完成後請開啟此畫面並請助教檢查"
echo ">> There is no auto grading in this lab. Please open this screen, then ask teaching assistant to check the lab."

exit 0
