#include "TempChartQWidget.h"

//#include <QCharts>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QLegend>
#include <QtCore/QDebug>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_CHARTS_USE_NAMESPACE

TempChartQWidget::TempChartQWidget(QWidget *parent) : QWidget(parent) {
    // Create buttons for ui

    //    m_buttonLayout = new QGridLayout();

    QPushButton *detachLegendButton = new QPushButton("Toggle attached");
    connect(detachLegendButton, &QPushButton::clicked, this, &TempChartQWidget::toggleAttached);
    m_buttonLayout.addWidget(detachLegendButton, 0, 0);

    QPushButton *addSetButton = new QPushButton("add barset");
    connect(addSetButton, &QPushButton::clicked, this, &TempChartQWidget::addBarset);
    m_buttonLayout.addWidget(addSetButton, 2, 0);
    QPushButton *removeBarsetButton = new QPushButton("remove barset");
    connect(removeBarsetButton, &QPushButton::clicked, this, &TempChartQWidget::removeBarset);
    m_buttonLayout.addWidget(removeBarsetButton, 3, 0);

    QPushButton *alignButton = new QPushButton("Align (Bottom)");
    connect(alignButton, &QPushButton::clicked, this, &TempChartQWidget::setLegendAlignment);
    m_buttonLayout.addWidget(alignButton, 4, 0);

    QPushButton *boldButton = new QPushButton("Toggle bold");
    connect(boldButton, &QPushButton::clicked, this, &TempChartQWidget::toggleBold);
    m_buttonLayout.addWidget(boldButton, 8, 0);

    QPushButton *italicButton = new QPushButton("Toggle italic");
    connect(italicButton, &QPushButton::clicked, this, &TempChartQWidget::toggleItalic);
    m_buttonLayout.addWidget(italicButton, 9, 0);

    //    m_legendPosX = new QDoubleSpinBox();
    //    m_legendPosY = new QDoubleSpinBox();
    //    m_legendWidth = new QDoubleSpinBox();
    //    m_legendHeight = new QDoubleSpinBox();

    connect(&m_legendPosX,
            static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
            this, &TempChartQWidget::updateLegendLayout);
    connect(&m_legendPosY,
            static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
            this, &TempChartQWidget::updateLegendLayout);
    connect(&m_legendWidth,
            static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
            this, &TempChartQWidget::updateLegendLayout);
    connect(&m_legendHeight,
            static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
            this, &TempChartQWidget::updateLegendLayout);

    QFormLayout *legendLayout = new QFormLayout();
    legendLayout->addRow("HPos", &m_legendPosX);
    legendLayout->addRow("VPos", &m_legendPosY);
    legendLayout->addRow("Width", &m_legendWidth);
    legendLayout->addRow("Height", &m_legendHeight);
    //    m_legendSettings = new QGroupBox("Detached legend");
    m_legendSettings.setLayout(legendLayout);
    m_buttonLayout.addWidget(&m_legendSettings);
    m_legendSettings.setVisible(false);

    // Create chart view with the chart
    //    m_chart = new QChart();
    //    m_chartView = new QChartView(m_chart, this); //
    m_chartView.setParent(this);
    m_chartView.setChart(&m_chart);
    // Create spinbox to modify font size
    //    m_fontSize = new QDoubleSpinBox();
    m_fontSize.setValue(m_chart.legend()->font().pointSizeF());
    connect(&m_fontSize,
            static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
            this, &TempChartQWidget::fontSizeChanged);

    QFormLayout *fontLayout = new QFormLayout();
    fontLayout->addRow("Legend font size", &m_fontSize);

    // Create layout for grid and detached legend
    //    m_mainLayout = new QGridLayout();
    /*
    m_mainLayout->addLayout(m_buttonLayout, 0, 0);
    */
    /*
    m_mainLayout->addLayout(fontLayout, 1, 0);
    */
    m_mainLayout.addWidget(&m_chartView, 0, 1, 3, 1);
    setLayout(&m_mainLayout);

    createSeries();
}

void TempChartQWidget::createSeries() {
    //    m_series = new QBarSeries();
    addBarset();
    addBarset();
    addBarset();
    addBarset();

    m_chart.addSeries(&m_series);
    m_chart.setTitle("Untitled Commitment 0");
    m_chart.createDefaultAxes();
    //![1]
    m_chart.legend()->setVisible(true);
    m_chart.legend()->setAlignment(Qt::AlignBottom);
    //![1]

    m_chartView.setRenderHint(QPainter::Antialiasing);
}

void TempChartQWidget::showLegendSpinbox() {
    m_legendSettings.setVisible(true);
    QRectF chartViewRect = m_chartView.rect();

    m_legendPosX.setMinimum(0);
    m_legendPosX.setMaximum(chartViewRect.width());
    m_legendPosX.setValue(150);

    m_legendPosY.setMinimum(0);
    m_legendPosY.setMaximum(chartViewRect.height());
    m_legendPosY.setValue(150);

    m_legendWidth.setMinimum(0);
    m_legendWidth.setMaximum(chartViewRect.width());
    m_legendWidth.setValue(150);

    m_legendHeight.setMinimum(0);
    m_legendHeight.setMaximum(chartViewRect.height());
    m_legendHeight.setValue(75);
}

void TempChartQWidget::hideLegendSpinbox() {
    m_legendSettings.setVisible(false);
}

void TempChartQWidget::toggleAttached() {
    QLegend *legend = m_chart.legend();
    if (legend->isAttachedToChart()) {
        //![2]
        legend->detachFromChart();
        m_chart.legend()->setBackgroundVisible(true);
        m_chart.legend()->setBrush(QBrush(QColor(128, 128, 128, 128)));
        m_chart.legend()->setPen(QPen(QColor(192, 192, 192, 192)));
        //![2]
        showLegendSpinbox();
        updateLegendLayout();
    } else {
        //![3]
        legend->attachToChart();
        legend->setBackgroundVisible(false);
        //![3]
        hideLegendSpinbox();
    }
    update();
}

void TempChartQWidget::addBarset() {
    QBarSet *barSet =
        new QBarSet(QString("session ") + QString::number(m_series.count()));
    qreal delta = m_series.count() * 0.1;
    *barSet << 1 + delta << 2 + delta << 3 + delta << 4 + delta;
    m_series.append(barSet);
}

void TempChartQWidget::removeBarset() {
    QList<QBarSet *> sets = m_series.barSets();
    if (sets.count() > 0) {
        m_series.remove(sets.at(sets.count() - 1));
    }
}

void TempChartQWidget::setLegendAlignment() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    switch (m_chart.legend()->alignment()) {
    case Qt::AlignTop:
        m_chart.legend()->setAlignment(Qt::AlignLeft);
        if (button)
            button->setText("Align (Left)");
        break;
    case Qt::AlignLeft:
        m_chart.legend()->setAlignment(Qt::AlignBottom);
        if (button)
            button->setText("Align (Bottom)");
        break;
    case Qt::AlignBottom:
        m_chart.legend()->setAlignment(Qt::AlignRight);
        if (button)
            button->setText("Align (Right)");
        break;
    default:
        if (button)
            button->setText("Align (Top)");
        m_chart.legend()->setAlignment(Qt::AlignTop);
        break;
    }
}

void TempChartQWidget::toggleBold() {
    QFont font = m_chart.legend()->font();
    font.setBold(!font.bold());
    m_chart.legend()->setFont(font);
}

void TempChartQWidget::toggleItalic() {
    QFont font = m_chart.legend()->font();
    font.setItalic(!font.italic());
    m_chart.legend()->setFont(font);
}

void TempChartQWidget::fontSizeChanged() {
    QFont font = m_chart.legend()->font();
    font.setPointSizeF(m_fontSize.value());
    m_chart.legend()->setFont(font);
}

void TempChartQWidget::updateLegendLayout() {
    //![4]
    m_chart.legend()->setGeometry(QRectF(m_legendPosX.value(), m_legendPosY.value(),
                                         m_legendWidth.value(), m_legendHeight.value()));
    m_chart.legend()->update();
    //![4]
}

TempChartQWidget::~TempChartQWidget() {
    qDebug("destructor TempChartQWidget#1");
    //    delete ui;
}
