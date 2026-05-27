# 🤖 AI Workflows — Learning Notes

A personal documentation of my journey learning AI workflows, including commands, skills, and agents.

---

## 📚 Table of Contents

- [What are AI Workflows?](#what-are-ai-workflows)
- [Commands](#commands)
- [Skills](#skills)
- [Agents](#agents)
- [How They Work Together](#how-they-work-together)
- [Tools & Platforms](#tools--platforms)
- [Resources](#resources)

---

## What are AI Workflows?

An **AI workflow** is a structured sequence of steps where AI models, tools, and logic are combined to complete a task — often automatically or with minimal human input.

Think of it like a pipeline:

```
User Input → AI Model → Tools/Skills → Output
```

Modern AI workflows can branch, loop, use memory, call external APIs, and even spawn sub-agents to handle parallel tasks.

---

## Commands

**Commands** are the instructions you give to an AI model. They tell the model *what to do*.

### Types of Commands

| Type | Description | Example |
|------|-------------|---------|
| **System Prompt** | Sets the AI's role and behavior | `"You are a helpful coding assistant."` |
| **User Prompt** | The direct instruction from the user | `"Summarize this document."` |
| **Tool Call** | Tells the AI to use a specific tool | `search_web("latest AI news")` |
| **Chained Command** | Output of one step becomes input for next | Summarize → Translate → Format |

### Best Practices for Writing Commands

- Be **specific** — vague instructions lead to vague outputs
- Use **positive framing** — say what to do, not just what to avoid
- Provide **examples** when possible (few-shot prompting)
- Use **XML tags** or structured formatting for complex prompts
- Ask for **step-by-step reasoning** on hard tasks (chain-of-thought)

### Example: A Good vs. Bad Command

```
❌ Bad:   "Write something about climate."

✅ Good:  "Write a 3-paragraph explainer on climate change for a 
          high school audience. Use simple language, include one 
          statistic per paragraph, and end with a call to action."
```

---

## Skills

**Skills** are reusable capabilities that an AI agent can call upon to complete specific tasks. They are like functions or tools that extend what the AI can do beyond just generating text.

### Types of Skills

| Skill Type | Description | Example |
|------------|-------------|---------|
| **Built-in** | Native capabilities of the model | Reasoning, summarization, translation |
| **Tool-based** | External tools the model can call | Web search, code execution, file reading |
| **Custom** | Skills you define for a specific use case | `analyze_sales_report`, `send_email` |
| **MCP Skills** | Model Context Protocol integrations | Google Drive, Slack, GitHub access |

### How Skills Work

```
1. User sends a message
2. AI decides if a skill/tool is needed
3. AI calls the skill with the right parameters
4. Skill returns a result
5. AI uses the result to form its response
```

### Example: Web Search Skill

```json
{
  "tool": "web_search",
  "input": {
    "query": "latest developments in AI agents 2025"
  },
  "output": "... search results ..."
}
```

### Tips for Working with Skills

- Give skills **clear, descriptive names**
- Define **input and output schemas** precisely
- Handle **errors gracefully** — tools can fail
- Log skill usage for **debugging and improvement**

---

## Agents

**Agents** are AI systems that can take actions, make decisions, and complete multi-step tasks — often with access to tools, memory, and the ability to plan.

### Agent vs. Basic AI Model

| Feature | Basic Model | Agent |
|---------|-------------|-------|
| Memory | None (per conversation) | Can persist across sessions |
| Tools | Sometimes | Yes — core capability |
| Planning | No | Yes — breaks tasks into steps |
| Autonomy | Low | High |
| Loops | No | Yes — can retry and adapt |

### Types of Agents

**1. ReAct Agent** (Reason + Act)
The agent reasons about what to do, takes an action, observes the result, and repeats.

```
Thought → Action → Observation → Thought → ...
```

**2. Plan-and-Execute Agent**
First creates a plan, then executes each step in order.

```
Goal → [Step 1, Step 2, Step 3] → Execute → Result
```

**3. Multi-Agent System**
Multiple agents work together, each with a specialized role.

```
Orchestrator Agent
    ├── Research Agent
    ├── Writing Agent
    └── Review Agent
```

### Agent Loop (Simplified)

```python
while task_not_complete:
    thought = agent.think(current_state)
    action = agent.decide_action(thought)
    result = execute_action(action)
    current_state = update_state(result)
```

### Key Agent Concepts

- **Memory** — Short-term (in context) vs. long-term (stored externally)
- **Planning** — Breaking a goal into sub-tasks
- **Tool Use** — Calling skills/APIs to get things done
- **Reflection** — Reviewing its own outputs and improving them
- **Handoff** — Passing work to another agent or human

---

## How They Work Together

Here's how **Commands**, **Skills**, and **Agents** connect in a real workflow:

```
┌─────────────────────────────────────────────────────┐
│                  USER GOAL                          │
│         "Research and write a blog post"            │
└──────────────────────┬──────────────────────────────┘
                       │
                       ▼
┌─────────────────────────────────────────────────────┐
│                ORCHESTRATOR AGENT                   │
│     Receives the command, makes a plan              │
└──────┬───────────────┬──────────────────────────────┘
       │               │
       ▼               ▼
┌──────────────┐  ┌───────────────┐
│ Research     │  │ Writing       │
│ Agent        │  │ Agent         │
│              │  │               │
│ Uses Skills: │  │ Uses Skills:  │
│ - web_search │  │ - text_gen    │
│ - summarize  │  │ - format_md   │
└──────┬───────┘  └───────┬───────┘
       │                  │
       └────────┬─────────┘
                ▼
        Final Blog Post ✅
```

---

## Tools & Platforms

Platforms and frameworks I'm exploring:

| Tool | What It Does |
|------|-------------|
| **Claude (Anthropic)** | AI model with strong reasoning and tool use |
| **Claude Code** | Agentic coding in the terminal |
| **LangChain** | Framework for building LLM-powered apps |
| **LangGraph** | Graph-based multi-agent orchestration |
| **n8n / Make** | Visual no-code workflow automation |
| **MCP (Model Context Protocol)** | Standard for connecting AI to external tools |
| **OpenAI Assistants API** | Hosted agents with memory and tools |

---

## Resources

- [Anthropic Docs](https://docs.anthropic.com) — Claude API, prompting guides
- [Prompt Engineering Guide](https://docs.claude.com/en/docs/build-with-claude/prompt-engineering/overview)
- [LangChain Docs](https://docs.langchain.com)
- [LangGraph Docs](https://langchain-ai.github.io/langgraph/)
- [Model Context Protocol](https://modelcontextprotocol.io)

---

> 📝 *This is a living document. I'll keep updating it as I learn more.*