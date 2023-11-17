#!/bin/bash
echo "Running tests..."
echo

# 加入輸入資料
output=$(echo 1 2 3 4 | ./a.out)

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
