#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/2/8 13:36
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : {NAME}.py
# @Software: PyCharm
"""
1.需求功能：
 

2.实现过程：
1. 输入字符串
2. 根据字符串长度来设定随机种子长度。
3.根据随机数来取字符串里面的字符。如果随机数长度超过字符串长度，则用字符串长度的模
4.

"""

import random
import hashlib
import os
import pymysql

PATH =os.path.dirname(__file__)
print(PATH)
OUTPATH=os.path.join(PATH,'out')
if not os.path.exists(OUTPATH):
    os.makedirs(OUTPATH)


def targetstr_to_upper(specical_str2):
    specical_str2_list = list(specical_str2)
    for index in range(len(specical_str2_list)):
        if specical_str2_list[index] >= 'a' and specical_str2_list[index] <= 'z':
            specical_str2_list[index] = specical_str2_list[index].upper()
    specical_str2 = ''.join(specical_str2_list)
    return specical_str2

def write_data(account,data):
    with open(os.path.join(OUTPATH,account+'.txt'),'w') as fp:
        fp.write(data)


if __name__ == '__main__':
    account = input("请输入账号：").strip()
    while len(account) < 1:
        print("输入账号不能为空！！")
        account = input("请输入账号：").strip()

    password_total_len = input("请输入密码长度：").strip()
    while not password_total_len.isdigit():
        print("输入的密码长度只能是整数：")
        password_total_len = input("请输入密码长度：").strip()
    password_total_len = int(password_total_len)

    is_all_number = input("密码是否全部是数字：Y/N：").strip()
    while (not is_all_number.isalpha()) or is_all_number.upper() not in ['Y', 'N']:
        print("密码是否全部是数字，只能输入Y/N，不区分大小写")
        is_all_number = input("密码是否全部是数字：Y/N：").strip()

    s1 = account.encode("utf-8")
    account = account.upper()
    s2 = account.encode("utf-8")
    specical_str1 = hashlib.md5(s1).hexdigest()
    specical_str2 = hashlib.md5(s2).hexdigest()

    ## 产生随机值，用于选定特殊符号
    mid = 0
    if len(specical_str1) == len(specical_str2):
        mid = len(specical_str1) // 2
    else:
        mid = int(len(specical_str2) // 2 if len(specical_str1) > len(specical_str2) else len(specical_str1) // 2)
    random.seed(specical_str1[0:mid])
    t1_random = str(int(random.random() * pow(10, 10)))
    random.seed(specical_str2[mid:])
    t2_random = str(int(random.random() * pow(10, 10)))
    if len(t1_random) < len(t2_random):
        t1_random += '0' * (len(t2_random) - len(t1_random))
    elif len(t1_random) > len(t2_random):
        t2_random += '0' * (len(t1_random) - len(t2_random))

    special_sign = ['~', '!', '#', '$', '%', '^', '&', '*', ';', ':', '"', '.', '?', '/', '=', '+', '|', '{', '}', '-',
                    '[', ']']

    select_special_data = []
    select_special_number = 0
    for index in range(len(t1_random)):
        select_index_str1 = int(t1_random[index])
        select_index_str2 = int(t2_random[index])
        powdata = pow(select_index_str1, select_index_str2) % len(special_sign)
        select_special_data.append(special_sign[powdata])
        select_special_number += powdata
    random.seed(select_special_number)
    specical_str2 = targetstr_to_upper(specical_str2)
    new_specical_str = list(specical_str1 + specical_str2 + ''.join(select_special_data))
    if len(new_specical_str) < password_total_len:
        new_specical_str += 'ZGL' * ((password_total_len - len(new_specical_str)) // 3)
    if len(new_specical_str) < password_total_len:
        new_specical_str += 'M' * (password_total_len - len(new_specical_str))

    random.shuffle(new_specical_str)

    password = []
    if is_all_number.lower() == 'n':
        for index in range(0, len(new_specical_str)):
            select1 = new_specical_str[index]
            select2 = new_specical_str[(0 - index)]
            password.append(select1)
            password.append(select2)
            if len(password) >= password_total_len:
                password = password[0:password_total_len]
                break
    else:
        for index in range(0, len(new_specical_str)):
            select1 = new_specical_str[index]
            select2 = new_specical_str[(0 - index)]
            if select1 >= '0' and select1 <= '9':
                password.append(select1)
            if select2 >= '0' and select2 <= '9':
                password.append(select2)
            if len(password) >= password_total_len:
                password = password[0:password_total_len]
                break
        while len(password) < password_total_len:
            password.append('0')
    password = ''.join(password)

    print("最终密码:")
    print(password)
    write_data(account, password)
    print("write finish!")
    try:
        conn = pymysql.connect(host='127.0.0.1',user='root',password='rootzgl',charset='utf8')
        cur = conn.cursor()
        # sql_select = "select account from user.personuser where account='%s'" %(account)
        # cur.execute(sql_select)
        # conn.commit()
        # select_data=cur.fetchone()

        sqlstr ="insert into user.personuser(account, password) value ('%s','%s')" %(account,password)
        print(sqlstr)
        cur.execute(sqlstr)
        conn.commit()
        print("insert success!")
    except:
        conn.rollback()

