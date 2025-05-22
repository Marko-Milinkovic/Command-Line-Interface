#include "SemanticRule.h"

void NoHasArgumentAndInPipeline::check(const Command& cmd) const
{
	if (cmd.getIsInPipeline() && cmd.getHasArgument() && !cmd.getFirstInPipeline()) {
		throw SemanticError("Command " + cmd.getOpcode().getText() + " cannot have argument while in pipeline\n");
	}
}

void NoRedirectionAndInPipeline::check(const Command& cmd) const
{
	if (cmd.getIsInPipeline()) {
		
		if (!cmd.getFirstInPipeline() && cmd.getHasRedirectedInput()) {
			throw SemanticError("Command " + cmd.getOpcode().getText() + " cannot have redirected input while in pipeline\n");
		}
		if (!cmd.getLastInPipeline() && cmd.getHasRedirectedOutput()) {
			throw SemanticError("Command " + cmd.getOpcode().getText() + " cannot have redirected output while in pipeline\n");
		}

	}
}
