
#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_



void TWI_voidMasterInit(void);
void TWI_voidSlaveInit(void);
void TWI_voidStartCondition(void);
void TWI_voidSendRepeatedStart(void);
void TWI_voidMasterSendSlaveAddWithWrite(u8 copy_u8Address);
void TWI_voidMasterSendSlaveAddWithRead(u8 copy_u8Address);
void TWI_voidMasterSendData(u8 copy_u8Data);
void TWI_u8MasterReceiveData(u8 *copy_u8data);
void TWI_voidStopCondition(void);
u8 TWI_u8SlaveReceiveData(void);


#endif /* TWI_INTERFACE_H_ */
