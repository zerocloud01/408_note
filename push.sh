#!/bin/bash

if [ -z "$1" ]; then
    echo "错误, 请提供commit信息"
    echo "用法: ./push.sh \"commit_name\""
    exit 1
fi

# 执行git命令
git add .
git commit -m "$1"
git push -u origin main