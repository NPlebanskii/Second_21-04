#include "signalslot.h"

#include <QWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QProgressBar>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QRadioButton>
#include <QGroupBox>


SignalSlot::SignalSlot(QWidget *parent)
    : QWidget(parent)
{
    QSpinBox *spinBox = new QSpinBox;
    QProgressBar *progressBar = new QProgressBar;
    QSlider *slider = new QSlider(Qt::Horizontal);

    spinBox->setMaximum(100);
    progressBar->setMaximum(100);
    slider->setMaximum(100);

    connect(spinBox, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));
    connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    connect(progressBar, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    connect(progressBar, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    connect(slider, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));

    QHBoxLayout *topLayout = new QHBoxLayout;

    topLayout->addWidget(spinBox);
    topLayout->addWidget(progressBar);
    topLayout->addWidget(slider);

    QPushButton *pushButton = new QPushButton("Click me");
    QCheckBox *checkBox = new QCheckBox("Check me");

    pushButton->setCheckable(true);


    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(pushButton);
    leftLayout->addWidget(checkBox);

    QRadioButton *radioButton1 = new QRadioButton("Button");
    QRadioButton *radioButton2 = new QRadioButton("CheckBox");

    connect(radioButton1, SIGNAL(toggled(bool)), pushButton, SLOT(setChecked(bool)));
    connect(radioButton2, SIGNAL(toggled(bool)), checkBox, SLOT(setChecked(bool)));
    connect(pushButton, SIGNAL(toggled(bool)), radioButton1, SLOT(setChecked(bool)));
    connect(checkBox, SIGNAL(toggled(bool)), radioButton2, SLOT(setChecked(bool)));

    QVBoxLayout *boxy = new QVBoxLayout;
    boxy->addWidget(radioButton1);
    boxy->addWidget(radioButton2);

    QGroupBox *groupBox = new QGroupBox("Boxy");
    groupBox->setLayout(boxy);
    groupBox->setCheckable(true);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addLayout(leftLayout);
    bottomLayout->addWidget(groupBox);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(topLayout);
    layout->addLayout(bottomLayout);

    setWindowTitle("Signal & Slots");
    setLayout(layout);

}

SignalSlot::~SignalSlot()
{

}
