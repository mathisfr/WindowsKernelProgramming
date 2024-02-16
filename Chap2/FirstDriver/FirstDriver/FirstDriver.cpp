#include <ntddk.h>

void FirstDriverUnload(_In_ PDRIVER_OBJECT DriverObject) {
	UNREFERENCED_PARAMETER(DriverObject);
	DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, "FirstDriver Unloaded.");
};

extern "C"
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(RegistryPath);
	RTL_OSVERSIONINFOW informationOS;

	DriverObject->DriverUnload = FirstDriverUnload;
	DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, "FirstDriver Loaded!");

	NTSTATUS returnType;
	returnType = RtlGetVersion(&informationOS);
	DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, "Major Version: %lu", informationOS.dwMajorVersion);
	DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, "Minor Version: %lu", informationOS.dwMinorVersion);
	DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, "Build Number: %lu", informationOS.dwBuildNumber);

	return returnType;
}