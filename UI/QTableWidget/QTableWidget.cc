
	ui->deviceTable->verticalHeader()->setFixedWidth(25); // 设置列表头宽度
	ui->deviceTable->horizontalHeader()->setFixedHeight(33);//设置行表头高度
	ui->deviceTable->verticalHeader()->setHidden(true); //隐藏列表头
	ui->deviceTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //表格内容自适应文本内容    
	ui->deviceTable->setAlternatingRowColors(true);//表格文本隔行换色