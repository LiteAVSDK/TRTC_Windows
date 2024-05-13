#include "test_network_check.h"

#include "defs.h"

#include "GenerateTestUserSig.h"
#include "room_info_holder.h"

TestNetworkCheck::TestNetworkCheck(QWidget *parent) :
    BaseDialog(parent),
    ui_test_network_check_(new Ui::TestNetworkCheckDialog)
{
    ui_test_network_check_->setupUi(this);
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
    getTRTCShareInstance()->addCallback(this);
}

TestNetworkCheck::~TestNetworkCheck(){
    getTRTCShareInstance()->removeCallback(this);
}

void TestNetworkCheck::startSpeedTest(std::string& userId){
    /** @note:  Do not use the code below in your commercial application. This is because:
     * The code may be able to calculate UserSig correctly, but it is only for quick testing of the SDK’s basic features, not for commercial applications.
     * SDKSECRETKEY in client code can be easily decompiled and reversed, especially on web.
     * Once your key is disclosed, attackers will be able to steal your Tencent Cloud traffic.
     * The correct method is to deploy the UserSig calculation code and encryption key on your project server so that your application can request from your server a UserSig that is calculated whenever one is needed.
     * Given that it is more difficult to hack a server than a client application, server-end calculation can better protect your key.
     * Documentation:  https://intl.cloud.tencent.com/document/product/647/35166#Server
     */
    getTRTCShareInstance()->startSpeedTest(SDKAppID, userId.c_str(),GenerateTestUserSig::genTestUserSig(userId.c_str(), SDKAppID,SDKSECRETKEY));
    is_network_checking = true;
    updateDynamicTextUI();
}

void TestNetworkCheck::stopSpeedTest(){
    getTRTCShareInstance()->stopSpeedTest();
    is_network_checking = false;
    updateDynamicTextUI();
}

//============= ITRTCCloudCallback start===================//

void TestNetworkCheck::onSpeedTest(const liteav::TRTCSpeedTestResult &currentResult, uint32_t finishedCount, uint32_t totalCount){
    QString result = QString("Progress: " + QString::number(finishedCount) + "/" + QString::number(totalCount)+"\n");
    result.append("ip:").append(QString::fromStdString(currentResult.ip))
            .append(" quality:").append(currentResult.quality)
            .append(" upLostRate:").append(QString::number(currentResult.upLostRate))
            .append(" downLostRate").append(QString::number(currentResult.downLostRate))
            .append(" rtt").append(QString::number(currentResult.rtt))
            .append("\n\n");
    ui_test_network_check_->resultQtb->append(result);

    if(finishedCount == totalCount){
        is_network_checking = false;
        updateDynamicTextUI();
    }
}

//============= ITRTCCloudCallback end===================//

void TestNetworkCheck::on_startSpeedTest_clicked(){
    if(is_network_checking){
        stopSpeedTest();
    }else{
        std::string uid = RoomInfoHolder::GetInstance().getUserId();
        if(uid.empty()){
            int rand = std::rand();
            uid = std::to_string(rand);
        }
        ui_test_network_check_->resultQtb->setText("");
        startSpeedTest(uid);
    }
}

void TestNetworkCheck::closeEvent(QCloseEvent *event)
{
    stopSpeedTest();
    BaseDialog::closeEvent(event);
}

void TestNetworkCheck::updateDynamicTextUI() {
    if (is_network_checking) {
        ui_test_network_check_->startSpeedTest->setText(tr("停止测试"));
    } else {
        ui_test_network_check_->startSpeedTest->setText(tr("开始测试"));
    }
}

void TestNetworkCheck::retranslateUi() {
    ui_test_network_check_->retranslateUi(this);
}