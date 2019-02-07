#include "FriendTree/FriendTree.h"
#include <QtWidgets/QApplication>
#include <algorithm>
#include <QTime>

using namespace qqfriendlist;

namespace
{
	// 群组名称
	std::vector < std::string > groups{ "我的家人", "我的朋友", "高中校友", "CSU", "铁道学院" };
	// 家人数据
	std::vector < std::string > familys{ "老爸", "老妈", "哥哥", "姑姑", "小姨" };
	// 朋友数据
	std::vector < std::string > friends{ "伟哥", "郭渣", "忘恩", "菜包", "小弟" };
	// 高中同学
	std::vector < std::string > highSchool{ "海洋", "宽宽", "嗯恩", "振", "小羊转" };
	// CSU
	std::vector < std::string > csu{ "张老师", "费老师", "刘老师", "胡老师", "郑老师" };
	// 铁道学院
	std::vector < std::string > csru{ "政委", "胜总", "小飞飞", "大兵", "逗比鱼" };

	// 信息列表
	std::vector<std::vector < std::string >> contactBasicInfo{ familys , friends, highSchool, csu, csru };
}

// 生成测试数据
auto createFriendDatas = [&]()
{
	static int qqNumber = 396396396; // 起始qq号 
	std::vector<Group> groupList{};
	for (int i = 0; i < groups.size(); i++)
	{
		// 创建5个分组
		Group group{};
		group.groupName = QString::fromLocal8Bit(groups[i].c_str());

		for (auto j = 0; j < contactBasicInfo[i].size(); j++)
		{
			Contact contact{};
			contact.name = contact.nickName = QString::fromLocal8Bit(contactBasicInfo[i][j].c_str());
			contact.id = QString::number(qqNumber++);
			contact.sex = ((j+1) % 2 == 0); // 生成性别
			contact.isVip = (j % 2 == 0);
			contact.onlineState = OnlineState(j);
			group.contactList.emplace_back(std::move(contact));
		}

		groupList.emplace_back(std::move(group));
	}

	return groupList;
};


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FriendTree w;
	// 传入数据
	w.setValues(createFriendDatas());
	w.setMinimumWidth(276);
    w.setMaximumWidth(600);

	w.resize(276, 500);
	w.show();
	return a.exec();
}
