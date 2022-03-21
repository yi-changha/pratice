#include "DisplayScene.h"
#include "Viewer.h"

// OpenCascade includes
#include <BinXCAFDrivers.hxx>
#include <STEPCAFControl_Reader.hxx>
#include <TDocStd_Application.hxx>
#include <TDocStd_Document.hxx>

//-----------------------------------------------------------------------------

namespace
{
    Handle(TDocStd_Document) ReadStepWithMeta(const char* filename)
    {
        STEPCAFControl_Reader Reader;

        // Create XDE document.
        Handle(TDocStd_Application) app = new TDocStd_Application;
        BinXCAFDrivers::DefineFormat(app);
        Handle(TDocStd_Document) doc;
        app->NewDocument("BinXCAF", doc);

        // Read CAD and associated data from file
        try
        {
            IFSelect_ReturnStatus outcome = Reader.ReadFile(filename);
            //
            if (outcome != IFSelect_RetDone)
            {
                app->Close(doc);
                return nullptr;
            }

            if (!Reader.Transfer(doc))
            {
                app->Close(doc);
                return nullptr;
            }
        }
        catch (...)
        {
            app->Close(doc);
            return nullptr;
        }

        return doc;
    }
}

//-----------------------------------------------------------------------------

int main(int argc, char** argv)
{
    Viewer vout(50, 50, 500, 500);

    if (argc > 1)
    {
        Handle(TDocStd_Document) doc = ::ReadStepWithMeta(argv[1]);
        //
        if (doc.IsNull())
        {
            std::cout << "Failed to read STEP model from file " << argv[1] << std::endl;
            return 1;
        }

        DisplayScene cmd(doc, vout.GetContext());
        if (!cmd.Execute())
        {
            std::cout << "Failed to visualize CAD model with `DisplayScene` command." << std::endl;
            return 1;
        }
    }

    vout.StartMessageLoop();
    return 0;
}
