/** @file    GlobalDefines.h
 *  @date    2019/02/04 11:17
 *  @brief   公共数据定义
 *
 *  @author  yu
 *  @contact ylesliefish@gmail.com
 */

#pragma once
#include <QObject>
#include <QMetaType>

namespace qqfriendlist
{
    // 在线状态
    enum class OnlineState
    {
        Online, // 在线
        Leave,  // 离开
        Busy,   // 忙碌
    };

    // 联系人结构
    struct Contact
    {
        QString name{};                     // 名字
        int sex{ 0 };                       // 性别 0男 1女
        QString nickName{};                 // 昵称
        QString id{};                       // QQ号
        QString signature{ QStringLiteral("新年快乐，心想事成") };// 个性签名
        QString headPortrait{};             // 头像路径
        OnlineState onlineState{ OnlineState::Online }; // 在线状态
        bool isVip{ 0 };                    // VIP类型 0不是vip; 1 vip; 2 svip 
    };

    // 分组
    struct Group
    {
        QString groupName{};
        std::vector<Contact> contactList{}; // 联系人列表
    };

    // 绘制角色
    enum class CustomRole
    {
        IsGroupRole = Qt::UserRole + 1000, // 是否是群组
        GroupNameRole,                     // 群组名称
        ContactRole,                       // 联系人信息
        IsExpandedRole,                    // 是否收起
        VideoRole,                         // 视频通话role
        SignatureRole,                     // 个性签名
        PortraitRole,                      // 头像
    };

    Q_DECLARE_METATYPE(Contact);
}