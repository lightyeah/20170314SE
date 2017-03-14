#include "configwindow.h"
#include "ui_configwindow.h"


ConfigWindow::ConfigWindow(QWidget *parent, DataProcessor *proceessor ) :
    QWidget(parent),
    ui(new Ui::ConfigWindow)
{
    ui->setupUi(this);
    UIsetting();
    connectsetting();
    workMode = 1;
    systemMode = 1;
}
ConfigWindow::~ConfigWindow()
{
    delete ui;
}
/*界面设置*/
void ConfigWindow::UIsetting()
{
    QLabel *systemmodelabel = new QLabel(this);
    systemModeBox = new QComboBox(this);
    QLabel *workmodelabel = new QLabel(this);
    workModeBox = new QComboBox(this);
    QLabel *monitertimeintervallabel = new QLabel(this);
    moniterTimeIntervalBox = new QComboBox(this);
    QLabel *coeffientlabel = new QLabel(this);
    coeffientSlider = new QSlider(this);
    coeffientSpinbox = new QSpinBox(this);
    systemmodelabel->setText(tr("系统配置： "));
    systemmodelabel->adjustSize();
    workmodelabel->setText(tr("工作模式： "));
    workmodelabel->adjustSize();
    monitertimeintervallabel->setText(tr("监控计时：(min)"));
    monitertimeintervallabel->adjustSize();
    coeffientlabel->setText(tr("互感系数： "));
    coeffientlabel->adjustSize();
    systemModeBox->addItem("windows");
    systemModeBox->addItem("linux");
    workModeBox->addItem("normal");
    workModeBox->addItem("test");
    moniterTimeIntervalBox->addItem(tr("1"));
    moniterTimeIntervalBox->addItem(tr("5"));
    moniterTimeIntervalBox->addItem(tr("10"));
    moniterTimeIntervalBox->addItem(tr("30"));
    moniterTimeIntervalBox->addItem(tr("100"));
    coeffientSlider->setOrientation(Qt::Horizontal);
    coeffientSlider->setMinimum(0);
    coeffientSlider->setMaximum(500);
    coeffientSlider->setSingleStep(1);
    coeffientSpinbox->setMinimum(0);
    coeffientSpinbox->setMaximum(500);
    coeffientSpinbox->setSingleStep(1);
    //coeffientSlider->setTickInterval(100);
    coeffientSlider->setValue(300);
    coeffientSpinbox->setValue(300);
    done = new QPushButton(this);
    done->setText(tr("done!"));
    QGridLayout *mainLayout = new QGridLayout;
    int line = 0;
    int row = 0;
    mainLayout->addWidget(systemmodelabel,line,row);row += 1;
    mainLayout->addWidget(systemModeBox,line,row);row += 1;
    line+=1;row=0;
    mainLayout->addWidget(workmodelabel,line,row);row += 1;
    mainLayout->addWidget(workModeBox,line,row);row += 1;
    line+=1;row=0;
    mainLayout->addWidget(monitertimeintervallabel,line,row);row+=1;
    mainLayout->addWidget(moniterTimeIntervalBox,line,row);row+=1;
    line+=1;row=0;
    mainLayout->addWidget(coeffientlabel,line,row);row+=1;
    mainLayout->addWidget(coeffientSlider,line,row);row+=1;
    mainLayout->addWidget(coeffientSpinbox,line,row);row+=1;
    line+=1;row=0;
    row = 1;
    mainLayout->addWidget(done,line,row);row += 1;
    setLayout(mainLayout);
    setWindowTitle(tr("ConfigWindow"));
}
/**
 * @brief ConfigWindow::connectsetting
 * 信号与槽的配置
 */
void ConfigWindow::connectsetting()
{
    QObject::connect(done,SIGNAL(clicked(bool)),this,SLOT(doneButtonClicked()));
    QObject::connect(systemModeBox,SIGNAL(currentTextChanged(QString)),this,SLOT(systemModeBoxChanged(QString)));
    QObject::connect(workModeBox,SIGNAL(currentTextChanged(QString)),this,SLOT(workModeBoxChanged(QString)));
    QObject::connect(moniterTimeIntervalBox,SIGNAL(currentTextChanged(QString)),this,SLOT(moniterTimeIntervalBoxChanged(QString)));
    QObject::connect(coeffientSlider,SIGNAL(valueChanged(int)),coeffientSpinbox,SLOT(setValue(int)));
    QObject::connect(coeffientSpinbox,SIGNAL(valueChanged(int)),coeffientSlider,SLOT(setValue(int)));
    QObject::connect(coeffientSlider,SIGNAL(valueChanged(int)),this,SLOT(coeffientChanged(int)));

}
/*
 * 确认配置完成
*/
void ConfigWindow::doneButtonClicked()
{
    emit systemModeSet(systemMode);
    emit workModeSet(workMode);
    emit moniterTimeIntervalSet(monitorTimeInterval);
    emit setDone();
    emit coeffientSet(coeffient);
    this->hide();//隐藏配置窗口
    this->setWindowFlags(Qt::Widget);
}
/**
 * @brief ConfigWindow::systemModeBoxChanged
 * @param systemtext
 */
void ConfigWindow::systemModeBoxChanged(QString systemtext)
{
    if(systemtext.contains("linux"))
    {
        systemMode = 2;//2 for linux system
    }
    else
    {
        systemMode = 1;//1 for windows system and others
    }
}
/**
 * @brief ConfigWindow::workModeBoxChanged
 */
void ConfigWindow::workModeBoxChanged(QString worktext)
{
    if(worktext.contains("test"))
    {
        workMode = 2;//2 for test mode
    }
    else
    {
        workMode = 1;//1 for normal and others
    }

}
/**
 * @brief ConfigWindow::moniterTimeIntervalBoxChanged
 * @param tt
 * 单位 min
 */
void ConfigWindow::moniterTimeIntervalBoxChanged(QString tt)
{
    monitorTimeInterval = tt.toInt();

}
/**
 * @brief ConfigWindow::coeffientChanged
 * @param coef
 */
void ConfigWindow::coeffientChanged(int coef)
{

   coeffient = coef;
}
