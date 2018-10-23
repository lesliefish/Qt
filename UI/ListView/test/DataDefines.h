#include <QObject>

#pragma once

enum PaintRoleType
{
    NameRole = Qt::UserRole + 2000,     // 用户名
    HeadPortraitRole,                   // 头像
    IsVipRole,                          // 是否vip
    DepartmentRole,                     // 部门Role
};


struct UserInfo
{
    bool isVip{ false };
    QString name{};
    QString depart{};
    QString headPortraitPath{};
};