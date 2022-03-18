// OpenCascade includes
#include <TDocStd_Application.hxx>
#include <TDataStd_Integer.hxx>
#include <BinDrivers.hxx>

int main()
{
	Handle(TDocStd_Application)
		app = new TDocStd_Application;
	//
	BinDrivers::DefineFormat(app);
	
	Handle(TDocStd_Document) doc;
	app->NewDocument("BinOcaf", doc);
	//
	if (doc.IsNull())
	{
		std::cout << "Error : cannot create an OCAF document" << std::endl;
		return 1;
	}

	/*	0
		|
		o-> 1(0:1) // main label
	*/

	TDF_Label mainLab = doc->Main();

	TDataStd_Integer::Set(mainLab, 199);

	PCDM_StoreStatus sstatus = app->SaveAs(doc, "C:/Users/USER/Desktop/test.cbf");
	//
	if (sstatus != PCDM_SS_OK)
	{
		app->Close(doc);

		std::cout << "Cannot write OCAF document." << std::endl;
		return 1;
	}

	app->Close(doc);
	return 0;
}